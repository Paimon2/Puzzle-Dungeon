#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include <string>
#include <fstream>
#include <iomanip>
//#include <fstream>
#include <iostream>
#include "json.hpp"
#include <chrono>
#include <thread>

int main() {

	sf::RenderWindow window(sf::VideoMode(1366, 818), "Settings");
	tgui::Gui gui(window);

	sf::Font font;
	font.loadFromFile("arial.ttf");

	sf::Music music;
	sf::SoundBuffer buffer;
	sf::Sound sound;
	sound.setBuffer(buffer);

	nlohmann::json data;
	std::ifstream i("GameData.json");
	i >> data;

	sf::Color trackColor(153, 76, 0);
	sf::Color thumbColor(128, 128, 128);

	float mvol = data["settings"]["music_volume"];
	float sfvol = data["settings"]["sound_volume"];

	auto label = tgui::Label::create();
   	label->setText("Volume: ");
   	label->setPosition("10%", "10%");
  	label->setTextSize(30);
  	label->getRenderer()->setTextColor(sf::Color::White);

	auto volslider = tgui::Slider::create();
	volslider->setValue(mvol/10);
	volslider->setPosition("10%", "20%");
	volslider->setSize("25%", "10%");
	volslider->getRenderer()->setTrackColor(trackColor);
	volslider->getRenderer()->setThumbColor(thumbColor);

	auto label2 = tgui::Label::create();
   	label2->setText("SoundFX: ");
   	label2->setPosition("10%", "40%");
  	label2->setTextSize(30);
  	label2->getRenderer()->setTextColor(sf::Color::White);

	auto sfxslider = tgui::Slider::create();
	sfxslider->setValue(sfvol/10); 
	sfxslider->setPosition("10%", "50%");
	sfxslider->setSize("25%", "10%");
	sfxslider->getRenderer()->setTrackColor(trackColor);
	sfxslider->getRenderer()->setThumbColor(thumbColor);

	auto progbar = tgui::ProgressBar::create();
	progbar->setPosition("30%", "45%");
	progbar->setSize("30%", "10%");
	progbar->getRenderer()->setFillColor(sf::Color::Green);

	gui.add(volslider);
	gui.add(sfxslider);
	gui.add(label);
	gui.add(label2);



	while (window.isOpen())
    {
    	float Vol = volslider->getValue(); // Get the value of the slider
    	Vol = Vol * 10.f;				   // Multiply it by 10
    	music.setVolume(Vol);			// Set the volume

    	float SFXVol = sfxslider->getValue();
        SFXVol = SFXVol * 10.f;
      	sound.setVolume(SFXVol); 

      	data["settings"]["music_volume"] = Vol;
      	data["settings"]["sound_volume"] = SFXVol;
        std::ofstream o("GameData.json");
		o <<  data << std::endl; 

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
            	gui.add(progbar);
            	for (int i = 0; i < 10; i++) {
            		float ni = i * 10;
            		progbar->setValue(ni); 
            		window.clear();
       				gui.draw();
        			window.display();
            		std::this_thread::sleep_for(std::chrono::milliseconds(20));
            	}
                window.close();
            } else {

            };
			
			gui.handleEvent(event);
        } 

         // std::cout << "Music: " << Vol << " SFX: " << SFXVol << "\n";
   		

        window.clear();
        gui.draw();
        window.display();
    
   }
    return 0;

}