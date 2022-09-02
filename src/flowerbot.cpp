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
            event.reply("Flowers are pretty and nice to look at!");
        }
    });

    //create slash command event (/iris)
    bot.on_slashcommand([] (const dpp::slashcommand_t &event) {
        if(event.command.get_command_name() == "iris") {
            event.reply(
                "Iris is a genus of 260-300 species of flowering plants with showy flowers. It takes it name from the Greek word for a rainbow, which is also the name for the Greek goddess of the rainbow, Iris. You can read more at https://en.wikipedia.org/wiki/Iris_(plant)"
                );
        }
    });

    //when bot is ready to be connected
    bot.on_ready([&bot] (const dpp::ready_t &event) {
        //run registered commands once when bot is connected. prevents commands from being 
        //run repeatedly if bot reconnects.
        if(dpp::run_once<struct register_bot_commands>()) {
            bot.global_command_create(dpp::slashcommand("Flowers", "Flowers?", bot.me.id));
            bot.global_command_create(dpp::slashcommand("Iris", "Iris description.", bot.me.id));
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