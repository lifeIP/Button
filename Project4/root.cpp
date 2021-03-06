#include "lib.h"
#include "obj.h"


int main() {
	
	sf::Uint32 style = sf::Style::Fullscreen;
	sf::RenderWindow window(sf::VideoMode::getFullscreenModes()[0], "", style);
	//warehouse of objects+
	bool button_push[8];
	Button::set_window_ptr(&window);
	Button::set_f_lag(button_push, 8);
	Button button_0(0);
	std::vector<unsigned int> rgba = { 255, 255, 255, 255 };
	button_0.set_color(rgba, rgba, rgba, rgba);
	button_0.set_color_highlighting(&sf::Color::Blue, &sf::Color::Blue, &sf::Color::Blue, &sf::Color::Blue);
	sf::Texture texture;
	texture.loadFromFile("btexture.jpg");
	button_0.set_texture(&texture);
	Button button_1(1);
	button_1.set_button_pos(&sf::Vector2f(0, 70));
	button_1.set_color_highlighting(&sf::Color::Red, &sf::Color::Blue, &sf::Color::Red, &sf::Color::Blue);
	Button button_2(2);
	button_2.set_button_pos(&sf::Vector2f(0, 140));
	button_2.set_color_highlighting(&sf::Color::Green, &sf::Color::Blue, &sf::Color::Yellow, &sf::Color::Blue);
	Button button_3(3);
	button_3.set_button_pos(&sf::Vector2f(0, 210));
	button_3.set_color_highlighting(&sf::Color::Magenta, &sf::Color::Blue, &sf::Color::Blue, &sf::Color::White);
	//Button button_4(4);
	//Button button_5(5);
	//Button button_6(6);
	//Button button_7(7);
	//warehouse of objects-
	while (window.isOpen()) {
		sf::Event some_event;
		while (window.pollEvent(some_event)) {
			if (some_event.type == sf::Event::EventType::KeyPressed) {
				switch (some_event.key.code)
				{
				case sf::Keyboard::E:
					//inventory
					break;
				case sf::Keyboard::Escape:
					window.close();
					break;
				}
			}
			else if (some_event.type == sf::Event::EventType::MouseButtonReleased) {
				switch (some_event.mouseButton.button)
				{
				case sf::Mouse::Left:
					//button_1.button_monitoring();
					//button_2.button_monitoring();
					//button_3.button_monitoring();
					//button_4.button_monitoring();
					//button_5.button_monitoring();
					//button_6.button_monitoring();
					//button_7.button_monitoring();
					switch (Button::which_button_pressed())
					{
					case -1:
						std::cout << "-1" << std::endl;
						break;
					case 0:
						std::cout << "0" << std::endl;
						break;
					case 1:
						std::cout << "1" << std::endl;
						break;
					case 2:
						std::cout << "2" << std::endl;
						break;
					case 3:
						std::cout << "3" << std::endl;
						break;
					case 4:
						std::cout << "4" << std::endl;
						break;
					case 5:
						std::cout << "5" << std::endl;
						break;
					case 6:
						std::cout << "6" << std::endl;
						break;
					case 7:
						std::cout << "7" << std::endl;
						break;
					}
					break;

				case sf::Mouse::Right:

					break;
				}
			}
		}
		window.clear(sf::Color::White);
		//Place for the rendering function+
		window.draw(button_0);
		window.draw(button_1);
		window.draw(button_2);
		window.draw(button_3);
		button_0.button_monitoring();
		button_1.button_monitoring();
		button_2.button_monitoring();
		button_3.button_monitoring();
		//Place for the rendering function-
		window.display();
	}
	return 0;
}