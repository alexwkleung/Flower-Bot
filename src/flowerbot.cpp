#include "flowerbot.h"
#include "dpp/dpp.h"
#include <string>
#include <sstream>

void Bot::bot() {
    //open input file stream 
    //create key.txt in src directory and put key inside. make sure to gitignore it.
    std::ifstream apikey("../src/key.txt");

    //get content of input file stream and append it to the TOKEN string
    std::getline(apikey, this->TOKEN);

    //check if input file stream is open (directory check for existence)
    if(apikey.is_open()) {
        std::cout << "Directory of input file stream found!" << '\n' << std::flush;
        std::cout << "Discord API Token (DO NOT SHARE): " << this->TOKEN << '\n' << std::flush << '\n';
    } else if(!apikey.is_open()) {
        std::cout << "Directory of input file stream does not exist! Fix the directory and try again." << '\n' << std::flush << '\n';
    }

    //create cluster object (bot)
    dpp::cluster bot(TOKEN);

    //log bot to output stream
    bot.on_log(dpp::utility::cout_logger());

    //create slash command event (/flower)
    bot.on_slashcommand([] (const dpp::slashcommand_t &event) {
        if(event.command.get_command_name() == "flowers") {
            event.reply("Flowers are pretty and nice to look at! Fun fact: All the colours of all flowers can be combined to create a wonderful colour palette.");
        }
    });

    //create slash command event (/iris)
    bot.on_slashcommand([] (const dpp::slashcommand_t &event) {
        if(event.command.get_command_name() == "iris") {
            event.reply(
                "Iris (genus Iris), genus of about 300 species of plants in the family Iriacaeae, including some of the world's most popular and varied garden flowers. The diversity of the genus is centered in the north temperate zone, though some of its most handsome species are native to the Mediterranean and central Asian areas. The iris is (arguably) the fleur-de-lis of the French royalist standard. It is a popular subject of Japanese flower arrangement, and it is also the source of orrisroot, from which 'essence of violet' perfume is made. Read more at https://www.britannica.com/plant/Iris-plant-genus" 
                );
        }
    });

    //create slash command event (/daisy)
    bot.on_slashcommand([] (const dpp::slashcommand_t &event) {
        if(event.command.get_command_name() == "daisy") {
            event.reply(
                "Daisy, any of several species of flowering plants belonging to the aster family (Asteraceae). The name daisy commonly denotes the oxeye daisy (Leucantheumum vulgare), the Shasta daisy (L. xsuperbum), and the English, or true, daisy (Bellis perennis). These and other plants called daisies are distinguished by a composite flower head composed of 15 to 30 white ray flowers surroudning a center consisting of bright yellow disk flowers, though other colour combinations are common. Read more at https://www.britannica.com/plant/daisy"
            );
        }
    });

    //when bot is ready to be connected
    bot.on_ready([&bot] (const dpp::ready_t &event) {
        //run registered commands once when bot is connected. prevents commands from being 
        //run repeatedly if bot reconnects.
        if(dpp::run_once<struct register_bot_commands>()) {
            bot.global_command_create(dpp::slashcommand("Flowers", "Flowers", bot.me.id));
            bot.global_command_create(dpp::slashcommand("Iris", "Information about the Iris flower", bot.me.id));
            bot.global_command_create(dpp::slashcommand("Daisy", "Information about the Daisy flower", bot.me.id));
        }
    });

    //start cluster (bot)
    bot.start(dpp::st_wait);
}

int main() {
    Bot b;

    b.bot();

    return 0;
}