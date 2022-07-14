#pragma once
class Button : public sf::Drawable
{
public:
	static void set_window_ptr(sf::RenderWindow* window_);
	static void set_f_lag(bool* f_lag, int size);
	void set_font_size(const unsigned short& font_size);
	void set_offset_text(const sf::Vector2u& offset);
	void set_color(unsigned int r,  unsigned int g,  unsigned int b,  unsigned int a);
	void set_color(std::vector<unsigned int>rgba_0, std::vector<unsigned int>rgba_1, std::vector<unsigned int>rgba_2, std::vector<unsigned int>rgba_3);
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
	void set_color_highlighting(const sf::Color* color_highlight_0, const sf::Color* color_highlight_1, const sf::Color* color_highlight_2, const sf::Color* color_highlight_3);
	void button_monitoring();
	
private:
	sf::Color color_highlight_0; 
	sf::Color color_highlight_1;
	sf::Color color_highlight_2;
	sf::Color color_highlight_3;
	sf::Vector2i mouse_pos;
	sf::Vector2u offset;
	sf::Vector2f button_pos;
	sf::Vector2u button_size;
	std::vector<unsigned int>rgba_0;
	std::vector<unsigned int>rgba_1;
	std::vector<unsigned int>rgba_2;
	std::vector<unsigned int>rgba_3;
	std::vector<unsigned int>rgba_text;
	int button_number;
	unsigned short font_size;
	sf::Text text;
	sf::Font font;
	sf::VertexArray obj;
	void highlighting();
	void config_button_pos_size_texture_config();
	void config_button_text();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};