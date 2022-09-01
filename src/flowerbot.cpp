#include "flowerbot.h"
#include "dpp/dpp.h"
#include <string>

void Bot::bot() {
    //ADD TOKEN BEFORE USING BOT
    //*** REMOVE TOKEN BEFORE GIT PUSH! ***
    this->TOKEN;

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
            event.reply("Iris description here.");
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