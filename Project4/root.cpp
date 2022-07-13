#include "lib.h"
#include "obj.h"


int main() {
	
	sf::Uint32 style = sf::Style::Fullscreen;
	sf::RenderWindow window(sf::VideoMode::getFullscreenModes()[0], "", style);
	//warehouse of objects+
	bool button_push[8];
	Button::set_window_ptr(&window);
	Button::set_f_lag(button_push);
	Button button_0(0);
	Button button_1(1);
	Button button_2(2);
	Button button_3(3);
	Button button_4(4);
	Button button_5(5);
	Button button_6(6);
	Button button_7(7);
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