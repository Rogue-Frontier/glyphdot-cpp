#ifndef GLYPH_SURFACE_H
#define GLYPH_SURFACE_H

#include "glyph_font.h"

#include "core/templates/vector.h"
#include "scene/main/canvas_item.h"
#include "scene/2d/node_2d.h"
#include "core/math/color.h"

class GlyphSurface : public Node2D {
	GDCLASS(GlyphSurface, Node2D);
	struct GlyphCell {
		Color front;
		Color back;
		int glyph;
		void draw(CanvasItem *p_surface, Ref<GlyphFont> p_font, Vector2i p_pos) {
			Vector2i glyph_size = p_font->get_glyph_size();
			RID canvas = p_surface->get_canvas_item();
			p_surface->draw_rect(Rect2i(p_pos * glyph_size, glyph_size), back);
			p_font->font->draw_rect_region(canvas, Rect2i(p_pos * glyph_size, glyph_size), p_font->get_glyph_rect(glyph), front);
		}
	};
	void resize() {
		int count = get_glyph_count();
		if (count == 0) {
			return;
		}
		cells.resize(count);
	}
	GlyphCell *get_cell_pointer_at(int x, int y) const {
		return get_cell_pointer(pos_to_index(x, y));
	}
	GlyphCell *get_cell_pointer(int index) const {
		if (index > -1 && index < cells.size()) {
			GlyphCell *c = (GlyphCell *)(&cells[index]);
			return c;
		} else {
			return 0;
		}
	}
protected:
	bool _set(const StringName &p_name, const Variant &p_value);
	bool _get(const StringName &p_name, Variant &r_ret) const;
	void _get_property_list(List<PropertyInfo> *p_list) const;
	void _notification(int p_notification);
	static void _bind_methods();
public:
	static inline GlyphCell empty = GlyphCell{ Color::hex(0), Color::hex(0), 0 };
	Color default_back = Color::hex64(0);
	Color default_front = Color::hex64(0);
	Ref<GlyphFont> font;
	int grid_width;
	int grid_height;
	Vector<GlyphCell> cells;

	void clear() { cells.fill(GlyphCell{ default_front, default_back, 0 }); }
	int get_glyph_count() const { return grid_width * grid_height; }
	int get_grid_width() const { return grid_width; }
	void set_grid_width(int p_grid_width) {
		grid_width = p_grid_width;
		resize();
	}
	int get_grid_height() const { return grid_height; }
	void set_grid_height(int p_grid_height) {
		grid_height = p_grid_height;
		resize();
	}
	Vector2i get_grid_size() const { return Vector2i(grid_width, grid_height); }
	void set_grid_size(Vector2i p_grid_size) {
		grid_width = p_grid_size.x;
		grid_height = p_grid_size.y;
		resize();
	}
	void set_cell(int x, int y, int glyph, Color front, Color back) {
		int ind = pos_to_index(x, y);
		GlyphCell *cell = get_cell_pointer(ind);
		if (cell && font.is_valid()) {
			*cell = GlyphCell{ front, back, glyph };
		}
	}
	void set_back(int x, int y, Color back) {
		GlyphCell *cell = get_cell_pointer_at(x, y);
		if (cell) {
			cell->back = back;
		}
	}
	Color get_back(int x, int y) {
		GlyphCell *cell = get_cell_pointer_at(x, y);
		if (cell) {
			return cell->back;
		}
		return Color::hex(0);
	}
	void set_front(int x, int y, Color front) {
		GlyphCell *cell = get_cell_pointer_at(x, y);
		if (cell) {
			cell->front = front;
		}
	}
	Color get_front(int x, int y) {
		GlyphCell *cell = get_cell_pointer_at(x, y);
		if (cell) {
			return cell->front;
		}
		return Color::hex(0);
	}
	void set_glyph(int x, int y, int glyph) {
		int ind = pos_to_index(x, y);
		GlyphCell *cell = get_cell_pointer(ind);
		if (cell) {
			cell->glyph = glyph;
		}
	}
	int get_glyph(int x, int y) {
		GlyphCell *cell = get_cell_pointer_at(x, y);
		if (cell) {
			return cell->glyph;
		}
		return 0;
	}
	Vector2i index_to_pos(int ind) const { return Vector2i(ind % grid_width, ind / grid_width); }
	int pos_to_index(int x, int y) const { return y * grid_width + x;}

	void set_font(Ref<GlyphFont> p_font) {
		if (p_font.is_null()) {
			return;
		}
		font = p_font;
	}
	Ref<GlyphFont> get_font() const { return font; }
	GlyphSurface(){}
	~GlyphSurface() {}
};

#endif 
