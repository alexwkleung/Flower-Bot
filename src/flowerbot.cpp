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
                "Iris (genus Iris), genus of about 300 species of plants in the family Iriacaeae, including some of the world's most popular and varied garden flowers. The diversity of the genus is centered in the north temperate zone, though some of its most handsome species are native to the Mediterranean and central Asian areas. The iris is (arguably) the fleur-de-lis of the French royalist standard. It is a popular subject of Japanese flower arrangement, and it is also the source of orrisroot, from which 'essence of violet' perfume is made. \n\nIrises are either bulbous or rhizomatous (with thick creeping underground stems). In species with a rhizome, the stem is usually horizontal, robust, and ringed with leaf scars. It often grows partially exposed but is firmly rooted in the soil. Species of Iris native to southwestern Europe generally produce bulbs. This type of stem is short and conical, and from it many leaf bases arise, one inside the other. These bases are seamless and constitute the bulk of the bulb. Bulblets arise from the stem, between the leaf bases, to propagate the plant. \n\nRead more here: https://www.britannica.com/plant/Iris-plant-genus" 
                );
        }
    });

    //create slash command event (/daisy)
    bot.on_slashcommand([] (const dpp::slashcommand_t &event) {
        if(event.command.get_command_name() == "daisy") {
            event.reply(
                "Daisy, any of several species of flowering plants belonging to the aster family (Asteraceae). The name daisy commonly denotes the oxeye daisy (Leucantheumum vulgare), the Shasta daisy (L. xsuperbum), and the English, or true, daisy (Bellis perennis). These and other plants called daisies are distinguished by a composite flower head composed of 15 to 30 white ray flowers surroudning a center consisting of bright yellow disk flowers, though other colour combinations are common. \n\nThe oxeye daisy is native to Europe and Asia but has become a common wild plant in the United States and elsewhere. This perennial grows to a height of about 60 cm (2 feet) and has oblong incised leaves and long petioles (leafstalks). Its solitary flower heads are about 2.5 to 5 cm (1 to 2 inches) in diameter, and the ray flowers are white in colour. The cultivated Shashta daisy resembles the oxeye daisy but has larger flower heads that may reach a diameter of 10 cm (4 inches). \n\nRead more here: https://www.britannica.com/plant/daisy"
            );
        }
    });

    //create slash command event (/tulip)
    bot.on_slashcommand([] (const dpp::slashcommand_t &event) {
        if(event.command.get_command_name() == "tulip") {
            event.reply(
                "Tulip. (genus Tulipa), genus of about 100 species of bulbous herbs in the lily family (Lilaceae), native to Central Asia and Turkey. Tulips are among the most popular of all garden flowers, and numerous cultivars and varieties have been developed. \n\nThe tulip produces two or three bluish green leavs that are clustered at the base of the plant. The usually solitary bell-shaped flowers have three petals and three sepals. There are six free staments, and the three-lobed ovary is terminated by a sessile three-lobed stigma. The fruit is a capsule with many seeds. Many garden tulips can be propagated only by their scaly bulbs. \n\nRead more here: https://www.britannica.com/plant/tulip"
            );
        }
    });

    //create slash command event (/lily)
    bot.on_slashcommand([] (const dpp::slashcommand_t &event) {
        if(event.command.get_command_name() == "lily") {
            event.reply(
                "Lily, (genus Lilium), genus of 80 to 100 species of herbaceous flowering plants of the family Liliaceae, native to temperate areas of the Northern Hemisphere. Many lilies are prized as ornamental plants, and they have been extensively hybridized. The word lily is also used in the common names of many plants of other genera that resemble true lilies. These include daylily (Hemerocallis) and various species of the family Amaryllidaceae. \n\nThe true lilies are erect perennial plants with leafy stems, scaly bulbs, usually narrow leavs, and solitary or clustered flowers. The flowers consist of six petal-like segments, which may form the shape of a trumpet, with a more or less elongated tube, as in the Madonna lily (Lilium candidum) and Easter Lily (L. longiflorum). Alternatively, the segments may be reflexed (curved back) to form  a turban shape, as in the Turk's cap lily (L. martagon), or they may be less strongly reflexed and form an open cup or bowl shape, as in the wood lily (L. philadelphicum) and goldband lily (L. auratum). The flowers of some species are quite fragrant, and they occur in a wide variety of colours. Plants of most species range in height from 30 to 120 cm (1 to 4 feet); plants of certain species, however, exceed 2.5 metres (8 feet) in height. \n\nRead more here: https://www.britannica.com/plant/lily"
            );
        }
    });

    //create slash command event (/orchid)
    bot.on_slashcommand([] (const dpp::slashcommand_t &event) {
        if(event.command.get_command_name() == "orchid") {
            event.reply(
                "Orchid, (family Orchidaceae), any of nearly 1000 genera and more than 25,000 species of attractively flowered plants distributed throughout the world, especially in wet tropics. Orchidaceae is a member of Asparagales, an order of monocotyledonous flowering plants that also includes the asparagus and iris families. The word orchid is derived from the Greek word (orchis) for testicle because of the shape of the root tubers in some species of the genus Orchis. These nonwoody perennial plants are generally terrestrial or epiphytic herbs (i.e., growing on other plants rather than rooted in soil). Those attached to other plants often are vinelike and have a spongy root covering called the velemen that absorbs water from the surrounding air. Most species manufacture their own food, but some live on dead organic material (saprophytic) or are helped to obtain nourishment by a fungus living in their roots. \n\nThe sepals and petals are usually quite distinct and thereforce retain their separate identification. The petal opposite the fertile stamen is called the lip, or labellum. Often two, or even all three, of the sepals are joined, and the lip, petals, or the sepals may be joined to the column for some distance. One of the characteristic differences between the orchid family and other advanced monocots is that the fertile stamen or stamens are on one side of the flower opposite the lip. This amkes the flower bilaterally symmetrical. \n\nRead more here: https://www.britannica.com/plant/orchid"
            );
        }
    });

    //create slash command event (/carnation)
    bot.on_slashcommand([] (const dpp::slashcommand_t &event) {
        if(event.command.get_command_name() == "carnation") {
            event.reply(
                "Carnation (Dianthus caryophyllus), also called grenadine or clove pink, herbaceous plant of the pink, or carnation, family (Caryophyllaceae), native to the Mediterranean area. It is widely cultivated for its fringe-petaled flowers, which often have a spicy fragrance, and is used extensively in the floral industry. \n\nThere are two general groups, the border, or garden, carnations, and the perpetual flowering carnations. Border carnations include a range of varieties and hybrids, 30 to 75cm (1 to 2.5 feet) tall; the flowers, in a wide range of colours, are usually less than 5cm (2 inches) in diameter and are borne on wiry; stiffly erect stems. The bluish green leavs are narrow, sheathing the stems; there are swellings at the junction of leaf and stem. \n\nRead more here: https://www.britannica.com/plant/carnation"
            );
        }
    });

    //create slash command event (/fresia)
    bot.on_slashcommand([] (const dpp::slashcommand_t &event) {
        if(event.command.get_command_name() == "freesia") {
            event.reply(
                "Freesia, (genus Freesia), genus of about 20 species perennial plants of the iris family (Iridaceae) native to southern Africa. The plants are grown indoors in pots or in gardens in mild climates, and the cut flowers are important in the floral industry. \n\nFreesia plants have grassy foliage that arises from underground corms (bulblike structures). They bear wiry spikes of lemon-scented flowers in white, yellow, orange, and blue. The approximately 60-centimeter-(2-foot)- tall flower spikes usually turn at right angles from the stem, displaying the flowers in a horizontal line or gentle arch. \n\nRead more here: https://www.britannica.com/plant/freesia"
            );
        }
    });

    //create slash command event (/chrysanthemum)
    bot.on_slashcommand([] (const dpp::slashcommand_t &event) {
        if(event.command.get_command_name() == "chrysanthemum") {
            event.reply(
                "Chrysanthemum, (genus Chrysanthemum), genus of about 40 species of flowering plants in the aster family (Asteraceae), native primarily to subtropical and temperate areas of the Old World. Chrysanthemums are especially common in East Asia, where they are often depicted in art, and many are popular ornamentals. \n\nMost plants of the genus are perennial herbs or subshrubs. Many have simple aromatic leaves that alternate along the stem. Some have both disk and ray flowers in the heads, but others lack ray or disk flowers. Cultivated species and hybrids usually have large flower heads; those of wild species are much smaller. \n\nRead more here: https://www.britannica.com/plant/Chrysanthemum"
            );
        }
    });

    //create slash command event (/gladiolus)
    bot.on_slashcommand([] (const dpp::slashcommand_t &event) {
        if(event.command.get_command_name() == "gladiolus") {
            event.reply(
                "Gladiolus, (genus Gladiolus), also called gladiola, plural gladioli, gladiolus, or gladioluses, genus of about 300 species of flowering plants of the iris family (Iridaceae), native to Europe, Africa, and the Mediterranean area. Several species are widely cultivated for cut flowers and as garden ornamentals. \n\nThe flowering spike, which springs from a bulblike structure, the corm, can reach 60-90cm (2-3 feet) in height. It bears numerous funnel-shaped flowers all clustered on one side of the stem, each with six petal-like floral parts. The leaves are sparse and swordlike. \n\nRead more here: https://www.britannica.com/plant/Gladiolus"
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
            bot.global_command_create(dpp::slashcommand("Freesia", "Information about the Freesia flower", bot.me.id));
            bot.global_command_create(dpp::slashcommand("Chrysanthemum", "Information about the Chrysanthemum flower", bot.me.id));
            bot.global_command_create(dpp::slashcommand("Gladiolus", "Information about the Gladiolus flower", bot.me.id));
        }
    });

    /*
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