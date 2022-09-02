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
            event.reply("Flowers are pretty and nice to look at! Fun fact: The colours of all flowers can be combined to create a wonderful colour palette. :smile:");
        }
    });

    //create slash command event (/iris)
    bot.on_slashcommand([] (const dpp::slashcommand_t &event) {
        if(event.command.get_command_name() == "iris") {
            event.reply(
                "Iris (genus Iris), genus of about 300 species of plants in the family Iriacaeae, including some of the world's most popular and varied garden flowers. The diversity of the genus is centered in the north temperate zone, though some of its most handsome species are native to the Mediterranean and central Asian areas. The iris is (arguably) the fleur-de-lis of the French royalist standard. It is a popular subject of Japanese flower arrangement, and it is also the source of orrisroot, from which 'essence of violet' perfume is made. Read more here: https://www.britannica.com/plant/Iris-plant-genus" 
                );
        }
    });

    //create slash command event (/daisy)
    bot.on_slashcommand([] (const dpp::slashcommand_t &event) {
        if(event.command.get_command_name() == "daisy") {
            event.reply(
                "Daisy, any of several species of flowering plants belonging to the aster family (Asteraceae). The name daisy commonly denotes the oxeye daisy (Leucantheumum vulgare), the Shasta daisy (L. xsuperbum), and the English, or true, daisy (Bellis perennis). These and other plants called daisies are distinguished by a composite flower head composed of 15 to 30 white ray flowers surroudning a center consisting of bright yellow disk flowers, though other colour combinations are common. Read more here: https://www.britannica.com/plant/daisy"
            );
        }
    });

    //create slash command event (/tulip)
    bot.on_slashcommand([] (const dpp::slashcommand_t &event) {
        if(event.command.get_command_name() == "tulip") {
            event.reply(
                "Tulip. (genus Tulipa), genus of about 100 species of bulbous herbs in the lily family (Lilaceae), native to Central Asia and Turkey. Tulips are among the most popular of all garden flowers, and numerous cultivars and varieties have been developed. Read more here: https://www.britannica.com/plant/tulip"
            );
        }
    });

    //create slash command event (/lily)
    bot.on_slashcommand([] (const dpp::slashcommand_t &event) {
        if(event.command.get_command_name() == "lily") {
            event.reply(
                "Lily, (genus Lilium), genus of 80 to 100 species of herbaceous flowering plants of the family Liliaceae, native to temperate areas of the Northern Hemisphere. Many lilies are prized as ornamental plants, and they have been extensively hybridized. The word lily is also used in the common names of many plants of other genera that resemble true lilies. These include daylily (Hemerocallis) and various species of the family Amaryllidaceae. Read more here: https://www.britannica.com/plant/lily"
            );
        }
    });

    //create slash command event (/orchid)
    bot.on_slashcommand([] (const dpp::slashcommand_t &event) {
        if(event.command.get_command_name() == "orchid") {
            event.reply(
                "Orchid, (family Orchidaceae), any of nearly 1000 genera and more than 25,000 species of attractively flowered plants distributed throughout the world, especially in wet tropics. Orchidaceae is a member of Asparagales, an order of monocotyledonous flowering plants that also includes the asparagus and iris families. The word orchid is derived from the Greek word (orchis) for testicle because of the shape of the root tubers in some species of the genus Orchis. These nonwoody perennial plants are generally terrestrial or epiphytic herbs (i.e., growing on other plants rather than rooted in soil). Those attached to other plants often are vinelike and have a spongy root covering called the velemen that absorbs water from the surrounding air. Most species manufacture their own food,  but some live on dead organic material (saprophytic) or are helped to obtain nourishment by a fungus living in their roots. Read more here: https://www.britannica.com/plant/orchid"
            );
        }
    });

    //create slash command event (/carnation)
    bot.on_slashcommand([] (const dpp::slashcommand_t &event) {
        if(event.command.get_command_name() == "carnation") {
            event.reply(
                "Carnation (Dianthus caryophyllus), also called grenadine or clove pink, herbaceous plant of the pink, or carnation, family (Caryophyllaceae), native to the Mediterranean area. It is widely cultivated for its fringe-petaled flowers, which often have a spicy fragrance, and is used extensively in the floral industry. Read more here: https://www.britannica.com/plant/carnation"
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
            bot.global_command_create(dpp::slashcommand("Tulip", "Information about the Tulip flower", bot.me.id));
            bot.global_command_create(dpp::slashcommand("Lily", "Information about the Lily flower", bot.me.id));
            bot.global_command_create(dpp::slashcommand("Orchid", "Information about the Orchid flower", bot.me.id));
            bot.global_command_create(dpp::slashcommand("Carnation", "Information about the Carnation flower", bot.me.id));
        }
    });

    /*
    Fressia
    Chrysanthemum
    Gladiolus
    Anemone
    Daffodil
    Poppy
    Buttercup
    Camellia
    Cosmos
    Crocus
    Sunflower
    Dandelion
    Jasmine
    Blossom
    Lavender
    Rose
    */

    //start cluster (bot)
    bot.start(dpp::st_wait);
}

int main() {
    Bot b;

    b.bot();

    return 0;
}