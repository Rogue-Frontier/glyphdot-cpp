#ifndef SADFONT_H
#define SADFONT_H
#include "core/io/resource.h"
#include "core/math/vector2i.h"
#include "core/math/rect2i.h"
#include "scene/resources/texture.h"

class SadFont : public Resource {
	GDCLASS(SadFont, Resource);

	protected:
	static void _bind_methods();

public:
	Ref<Texture2D> font;
	int glyph_width;
	int glyph_height;
	int glyph_padding;
	int columns;
	int solid_glyph_index;

	void set_font(Ref<Texture2D> p_font) { font = p_font; }
	Ref<Texture2D> get_font() const { return font; }

	void set_glyph_width(int p_glyph_width) { glyph_width = p_glyph_width; }
	int get_glyph_width() const { return glyph_width; }

	void set_glyph_height(int p_glyph_height) { glyph_height = p_glyph_height; }
	int get_glyph_height() const { return glyph_height; }

	
	void set_glyph_padding(int p_glyph_padding) { glyph_padding = p_glyph_padding; }
	int get_glyph_padding() const { return glyph_padding; }

	void set_columns(int p_columns) { columns = p_columns; }
	int get_columns() const { return columns; }

	void set_solid_glyph_index(int p_solid_glyph_index) { solid_glyph_index = p_solid_glyph_index; }
	int get_solid_glyph_index() const { return solid_glyph_index; }

	Vector2i get_glyph_size() const { return Vector2i(glyph_width, glyph_height); }

	Rect2i get_glyph_rect(int index) const;


	SadFont() {}
	~SadFont() {}
};
#endif
