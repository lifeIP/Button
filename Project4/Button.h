#pragma once
class Button : public sf::Drawable
{
public:
	static void set_window_ptr(sf::RenderWindow* window_);
	static void set_f_lag(bool* f_lag);
	void set_font_size(const unsigned short& font_size);
	void set_offset_text(const sf::Vector2u& offset);
	void set_color(const unsigned int& r, const unsigned int& g, const unsigned int& b, const unsigned int& a);
	void set_color_text(const unsigned int& r, const unsigned int& g, const unsigned int& b, const unsigned int& a);
	void set_font(const std::string& font_name);
	void set_text(const std::string& text);
	void set_button_pos(sf::Vector2f* button_pos);
	sf::Vector2f get_button_pos() const;
	void set_button_size(sf::Vector2u* button_size);
	sf::Vector2u get_button_size() const;
	
	Button(int button_number);

	~Button();
	static int which_button_pressed();
	void highlighting(sf::Color* color_highlight_0, sf::Color* color_highlight_1, sf::Color* color_highlight_2, sf::Color* color_highlight_3);
	void button_monitoring();
	
private:
	sf::Vector2i mouse_pos;
	sf::Vector2u offset;
	sf::Vector2f button_pos;
	sf::Vector2u button_size;
	std::vector<unsigned int>rgba;
	std::vector<unsigned int>rgba_text;
	int button_number;
	unsigned short font_size;
	sf::Text text;
	sf::Font font;
	sf::Texture texture;
	sf::VertexArray obj;
	void config_button_pos_size_texture_config();
	void config_button_text();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};