#include "glyph_font.h"
#include "core/math/rect2i.h"

Rect2i GlyphFont::get_glyph_rect(int index) const {
	int y = floorl(index / columns);
	int x = index % columns;
	Vector2i glyph_size = get_glyph_size();
	Rect2i result(Vector2i(x, y) * glyph_size, glyph_size);
	return result;
}
void GlyphFont::_bind_methods() {
	ClassDB::bind_method(D_METHOD("set_font", "texture"), &set_font);
	ClassDB::bind_method(D_METHOD("get_font"), &get_font);

	ClassDB::bind_method(D_METHOD("set_glyph_width", "width"), &set_glyph_width);
	ClassDB::bind_method(D_METHOD("get_glyph_width"), &get_glyph_width);

	ClassDB::bind_method(D_METHOD("set_glyph_height", "height"), &set_glyph_height);
	ClassDB::bind_method(D_METHOD("get_glyph_height"), &get_glyph_height);
	
	ClassDB::bind_method(D_METHOD("set_glyph_padding", "padding"), &set_glyph_padding);
	ClassDB::bind_method(D_METHOD("get_glyph_padding"), &get_glyph_padding);

	ClassDB::bind_method(D_METHOD("set_columns", "count"), &set_columns);
	ClassDB::bind_method(D_METHOD("get_columns"), &get_columns);

	ClassDB::bind_method(D_METHOD("set_solid_glyph_index", "index"), &set_solid_glyph_index);
	ClassDB::bind_method(D_METHOD("get_solid_glyph_index"), &get_solid_glyph_index);

	ClassDB::bind_method(D_METHOD("get_glyph_size"), &get_glyph_size);
	ClassDB::bind_method(D_METHOD("get_glyph_rect", "index"), &get_glyph_rect);

	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "font", PROPERTY_HINT_RESOURCE_TYPE, "Texture2D"), "set_font", "get_font");
	ADD_PROPERTY(PropertyInfo(Variant::INT, "glyph_width"), "set_glyph_width", "get_glyph_width");
	ADD_PROPERTY(PropertyInfo(Variant::INT, "glyph_height"), "set_glyph_height", "get_glyph_height");
	ADD_PROPERTY(PropertyInfo(Variant::INT, "glyph_padding"), "set_glyph_padding", "get_glyph_padding");
	ADD_PROPERTY(PropertyInfo(Variant::INT, "columns"), "set_columns", "get_columns");
	ADD_PROPERTY(PropertyInfo(Variant::INT, "get_solid_glyph_index"), "set_solid_glyph_index", "get_solid_glyph_index");

	ADD_PROPERTY(PropertyInfo(Variant::VECTOR2I, "glyph_size"), "", "get_glyph_size");
}
