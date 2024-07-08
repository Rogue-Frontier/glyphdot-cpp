#include "sadfont.h"
#include "core/math/rect2i.h"

Rect2i SadFont::get_glyph_rect(int index) const {
	int y = floorl(index / columns);
	int x = index % columns;
	Vector2i glyph_size = get_glyph_size();
	Rect2i result(Vector2i(x, y) * glyph_size, glyph_size);
	return result;
}
void SadFont::_bind_methods() {
	ClassDB::bind_method(D_METHOD("set_font", "texture"), &SadFont::set_font);
	ClassDB::bind_method(D_METHOD("get_font"), &SadFont::get_font);

	ClassDB::bind_method(D_METHOD("set_glyph_width", "width"), &SadFont::set_glyph_width);
	ClassDB::bind_method(D_METHOD("get_glyph_width"), &SadFont::get_glyph_width);

	ClassDB::bind_method(D_METHOD("set_glyph_height", "height"), &SadFont::set_glyph_height);
	ClassDB::bind_method(D_METHOD("get_glyph_height"), &SadFont::get_glyph_height);

	
	ClassDB::bind_method(D_METHOD("set_glyph_padding", "padding"), &SadFont::set_glyph_padding);
	ClassDB::bind_method(D_METHOD("get_glyph_padding"), &SadFont::get_glyph_padding);

	ClassDB::bind_method(D_METHOD("set_columns", "count"), &SadFont::set_columns);
	ClassDB::bind_method(D_METHOD("get_columns"), &SadFont::get_columns);

	ClassDB::bind_method(D_METHOD("set_solid_glyph_index", "index"), &SadFont::set_solid_glyph_index);
	ClassDB::bind_method(D_METHOD("get_solid_glyph_index"), &SadFont::get_solid_glyph_index);


	ClassDB::bind_method(D_METHOD("get_glyph_size"), &SadFont::get_glyph_size);
	ClassDB::bind_method(D_METHOD("get_glyph_rect", "index"), &SadFont::get_glyph_rect);


	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "font", PROPERTY_HINT_RESOURCE_TYPE, "Texture2D"), "set_font", "get_font");
	ADD_PROPERTY(PropertyInfo(Variant::INT, "glyph_width"), "set_glyph_width", "get_glyph_width");
	ADD_PROPERTY(PropertyInfo(Variant::INT, "glyph_height"), "set_glyph_height", "get_glyph_height");
	ADD_PROPERTY(PropertyInfo(Variant::INT, "glyph_padding"), "set_glyph_padding", "get_glyph_padding");
	ADD_PROPERTY(PropertyInfo(Variant::INT, "columns"), "set_columns", "get_columns");
	ADD_PROPERTY(PropertyInfo(Variant::INT, "get_solid_glyph_index"), "set_solid_glyph_index", "get_solid_glyph_index");

	ADD_PROPERTY(PropertyInfo(Variant::VECTOR2I, "glyph_size"), "", "get_glyph_size");
}
