#include "lib.h"
#include "Button.h"

static sf::RenderWindow* window;
static bool* f_lag;
void Button::set_window_ptr(sf::RenderWindow* window_)
{
	window = window_;
}

void Button::set_f_lag(bool* f_lag_)
{
	f_lag = f_lag_;
}

void Button::set_font_size(const unsigned short& font_size)
{
	this->font_size = font_size;
}

void Button::set_offset_text(const sf::Vector2u& offset)
{
	this->offset = offset;
}

void Button::set_color(const unsigned int& r, const unsigned int& g, const unsigned int& b, const unsigned int& a)
{
	rgba[0] = r;
	rgba[1] = g;
	rgba[2] = b;
	rgba[3] = a;
	config_button_pos_size_texture_config();
}

void Button::set_color_text(const unsigned int& r, const unsigned int& g, const unsigned int& b, const unsigned int& a)
{
	rgba_text[0] = r;
	rgba_text[1] = g;
	rgba_text[2] = b;
	rgba_text[3] = a;
	config_button_text();
}

void Button::set_font(const std::string& font_name)
{
	font.loadFromFile(font_name);
	config_button_text();
}

void Button::set_text(const std::string& text)
{
	this->text.setString(text);
	config_button_text();
}

void Button::set_button_pos(sf::Vector2f* button_pos)
{
	this->button_pos = *button_pos;
	config_button_pos_size_texture_config();
}

sf::Vector2f Button::get_button_pos() const
{
	return button_pos;
}

void Button::set_button_size(sf::Vector2u* button_size)
{
	this->button_size = *button_size;
	config_button_pos_size_texture_config();
}

sf::Vector2u Button::get_button_size() const
{
	return button_size;
}

Button::Button(int button_number)
{
	button_pos = sf::Vector2f(0, 0);
	button_size = sf::Vector2u(400, 65);
	this->button_number = button_number;
	rgba = { 100,0,100,255 };
	rgba_text = { 0,0,0,255 };
	font.loadFromFile("001.ttf");
	text.setFont(font);
	font_size = 24;
	text.setCharacterSize(font_size);
	text.setFillColor(sf::Color::Yellow);
	text.setPosition(sf::Vector2f(button_pos.x + 5, button_pos.y + 5));
	offset = sf::Vector2u(5, 5);
	config_button_pos_size_texture_config();
}

Button::~Button()
{
	std::cout << "destructor called" << std::endl;
}

int Button::which_button_pressed()
{
	for (int i = 0; i < (sizeof(f_lag) / sizeof(bool)); i++) {
		if (f_lag[i]) {
			return i;
		}
	}
	return -1;
}

void Button::highlighting(sf::Color* color_highlight_0, sf::Color* color_highlight_1, sf::Color* color_highlight_2, sf::Color* color_highlight_3)
{
	obj[0] = sf::Vertex(sf::Vector2f(button_pos.x, button_pos.y), *color_highlight_0);
	obj[1] = sf::Vertex(sf::Vector2f(button_pos.x + button_size.x, button_pos.y), *color_highlight_1);
	obj[2] = sf::Vertex(sf::Vector2f(button_pos.x + button_size.x, button_pos.y + button_size.y), *color_highlight_2);
	obj[3] = sf::Vertex(sf::Vector2f(button_pos.x, button_pos.y + button_size.y), *color_highlight_3);
}

void Button::button_monitoring()
{
	mouse_pos = sf::Mouse::getPosition();
	if (mouse_pos.x > button_pos.x && mouse_pos.x < button_pos.x + button_size.x && mouse_pos.y > button_pos.y && mouse_pos.y < button_pos.y + button_size.y) {
		f_lag[button_number] = true;
	}
	else {
		if (f_lag[button_number]) {
			f_lag[button_number] = false;

		}
	}
}

void Button::config_button_pos_size_texture_config()
{
	obj.resize(4);
	obj.setPrimitiveType(sf::Quads);
	obj[0] = sf::Vertex(sf::Vector2f(button_pos.x, button_pos.y), sf::Color::Color(rgba[0], rgba[1], rgba[2], rgba[3]));
	obj[1] = sf::Vertex(sf::Vector2f(button_pos.x + button_size.x, button_pos.y), sf::Color::Color(rgba[0], rgba[1], rgba[2], 40));
	obj[2] = sf::Vertex(sf::Vector2f(button_pos.x + button_size.x, button_pos.y + button_size.y), sf::Color::Color(rgba[0], rgba[1], rgba[2], 40));
	obj[3] = sf::Vertex(sf::Vector2f(button_pos.x, button_pos.y + button_size.y), sf::Color::Color(rgba[0], rgba[1], rgba[2], rgba[3]));
}

void Button::config_button_text()
{
	text.setFont(font);
	text.setCharacterSize(font_size);
	text.setFillColor(sf::Color::Color(rgba_text[1], rgba_text[2], rgba_text[2], rgba_text[3]));
	text.setPosition(sf::Vector2f(button_pos.x + offset.x, button_pos.y + offset.y));
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.texture = &texture;
	target.draw(obj, states);
	target.draw(text);
}
