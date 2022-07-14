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
	button_0.set_color_highlighting(&sf::Color::Blue, &sf::Color::Blue, &sf::Color::Blue, &sf::Color::Blue);
	//Button button_1(1);
	//Button button_2(2);
	//Button button_3(3);
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
					button_0.button_monitoring();
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
		window.clear(sf::Color::Black);
		//Place for the rendering function+
		window.draw(button_0);
		//Place for the rendering function-
		window.display();
	}
	return 0;
}