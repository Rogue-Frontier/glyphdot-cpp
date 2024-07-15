#include "glyph_surface.h"
#include "register_types.h"
#include "core/object/class_db.h"
bool GlyphSurface::_set(const StringName &p_name, const Variant &p_value) {
	return false;
	if (true) {
	} else {
		return false;
	}
	return true;
}
bool GlyphSurface::_get(const StringName &p_name, Variant &r_ret) const {
	return false;
	if (true) {
	} else {
		return false;
	}
	return true;
}
void GlyphSurface::_get_property_list(List<PropertyInfo> *p_list) const {
	//p_list->push_back(PropertyInfo(Variant::BOOL, PNAME("current")));
}
void GlyphSurface::_bind_methods() {
	ClassDB::bind_method(D_METHOD("set_glyph", "x", "y", "glyph"), &set_glyph);
	ClassDB::bind_method(D_METHOD("get_glyph", "x", "y"), &get_glyph);
	ClassDB::bind_method(D_METHOD("set_front", "x", "y", "front"), &set_front);
	ClassDB::bind_method(D_METHOD("get_front", "x", "y"), &get_front);
	ClassDB::bind_method(D_METHOD("set_back", "x", "y", "back"), &set_back);
	ClassDB::bind_method(D_METHOD("get_back", "x", "y"), &get_back);

	ClassDB::bind_method(D_METHOD("set_cell", "x", "y", "glyph", "front", "back"), &set_cell);

	ClassDB::bind_method(D_METHOD("set_font", "font"), &set_font);
	ClassDB::bind_method(D_METHOD("get_font"), &get_font);

	ClassDB::bind_method(D_METHOD("set_grid_width", "width"), &set_grid_width);
	ClassDB::bind_method(D_METHOD("get_grid_width"), &get_grid_width);
	ClassDB::bind_method(D_METHOD("set_grid_height", "height"), &set_grid_height);
	ClassDB::bind_method(D_METHOD("get_grid_height"), &get_grid_height);
	ClassDB::bind_method(D_METHOD("set_grid_size", "size"), &set_grid_size);
	ClassDB::bind_method(D_METHOD("get_grid_size"), &get_grid_size);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "font", PROPERTY_HINT_RESOURCE_TYPE, "GlyphFont"), "set_font", "get_font");
	ADD_GROUP("Grid", "grid_");
	ADD_PROPERTY(PropertyInfo(Variant::INT, "grid_width"), "set_grid_width", "get_grid_width");
	ADD_PROPERTY(PropertyInfo(Variant::INT, "grid_height"), "set_grid_height", "get_grid_height");
	ADD_PROPERTY(PropertyInfo(Variant::VECTOR2I, "grid_size", PROPERTY_HINT_NONE, "suffix:m"), "set_grid_size", "get_grid_size");
}
void GlyphSurface::_notification(int p_what) {
	switch (p_what) {
		case NOTIFICATION_DRAW: {
			if (font.is_null()) {
				return;
			}
			for (int i = 0; i < cells.size(); i++) {
				Vector2i pos = index_to_pos(i);
				GlyphCell* cell = (GlyphCell*)(&cells[i]);
				cell->draw(this, font, pos);
			}
		} break;
	}
}
