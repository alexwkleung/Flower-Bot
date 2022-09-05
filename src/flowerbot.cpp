#include "flowerbot.h"
#include "dpp/dpp.h"
#include <string>
#include <fstream>

void FlowerBot::bot() {
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
    dpp::cluster bot(this->TOKEN, dpp::i_default_intents | dpp::i_message_content);

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

    //create slash command event (/freesia)
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
    
    //create slash command event (/anemone)
    bot.on_slashcommand([] (const dpp::slashcommand_t &event) {
        if(event.command.get_command_name() == "anemone") {
            event.reply(
                "Anemone, (genus Anemone), also called pasqueflower or windflower, any of more than 100 species of perennial plants in the buttercup family (Ranunculaceae). Many colourful varieties of the tuberous poppylike anemone, A. coronaria, are grown for the garden and florist's trade. Popular spring-flowering anemones, especially for naturalizing, are A. apennina, A. blanda, and A. pavonina. Other species, such as the Japanese anemone (A. hupehenis, or A. japonica), are favourite border plants for autumn flowering. Some species whose fruits bear a long plumose structure are placed in a separate section, Pulsatilla, often given the rank of genus. Anemones are distributed throughout the world but occur most commonly in woodlands and meadows of the north temperate zone. Many varieties are cultivated in gardens for ther colourful flowers. \n\nRead more here: https://www.britannica.com/plant/anemone"
            );
        }
    });

    //create slash command event (/daffodil)
    bot.on_slashcommand([] (const dpp::slashcommand_t &event) {
        if(event.command.get_command_name() == "daffodil") {
            event.reply(
                "Daffodil, (Narcissus pseudonarcissus), also called common daffodil or trumpet narcissus, bulb-forming plant in the armaryllis family (Armaryllidaceae), widely cultivated for its trumpetlike flowers. Daffodils are native to norther Europe and are grown in temperate climates around the world. The draffodil's popularity has resulted in the producted of many varieties; in addition to the classic yellow form, the trumpet and petals may themselves be of contrasting yellow, white, pink, or orange. \n\nRead more here: https://www.britannica.com/plant/daffodil"
            );
        }
    });

    //create slash command event (/poppy)
    bot.on_slashcommand([] (const dpp::slashcommand_t &event) {
        if(event.command.get_command_name() == "poppy") {
            event.reply(
                "Poppy, any of several flowering plants of the poppy family (Papaveracceae), especially species of the genus Papaver. Most poppies are found in the Northern Hemisphere, and several species of poppies are cultivated as garden ornamentals. \n\nPoppies have lobed or dissected leavs and milky sap. The buds are often nodding and are borne on solitary stalks. The flowers have four to six petals with numerous staments surrounding the ovary. The two sepals usually drop off as the petals unfold. The ovary develops into a spherical capsule topped by a disk formed by the stigmas. The many small seeds escape from pores beneath the disk when the capsule is shaken by the wind. \n\nRead more here: https://www.britannica.com/plant/poppy"
            );
        }
    });

    //create slash command event (/buttercup)
    bot.on_slashcommand([] (const dpp::slashcommand_t &event) {
        if(event.command.get_command_name() == "buttercup") {
            event.reply(
                "Buttercup, (genus Ranunculus), also called crowfoot, genus of about 300 species of herbaceous flowering plants in the family Ranunculaceae. Buttercups are distribued throughout the world and are especially common in woods and fields of the north temperate zone. \n\nMost buttercups have tuberous or fibrous roots. The flowewrs are solitary or loosely clustered and have green sepals, five to many glossy yellow (sometimes white) petals, and numerous male and female structures (stamens and pistils). Cultivated varieties have been bred in many colours. The leaves are highly variable, depending on the species. \n\nRead more here: https://www.britannica.com/plant/buttercup"
            );
        }
    });

    //create slash command event (/camellia)
    bot.on_slashcommand([] (const dpp::slashcommand_t &event) {
        if(event.command.get_command_name() == "camellia") {
            event.reply(
                "Camellia, genus of about 250 species of East Asian evergreen shrubs and trees belonging to the tea family (Theaceae), most notable for a few ornamental flowering species and for Camellia sinensis (sometimes called Thea sinensis), the source of tea. \n\nRead more here: https://www.britannica.com/plant/Camellia"
            );
        }
    });

    //create slash command event (/cosmos)
    bot.on_slashcommand([] (const dpp::slashcommand_t &event) {
        if(event.command.get_command_name() == "cosmos") {
            event.reply(
                "Cosmos, genus of garden plants of the family Asteraceae, containing about 40 species native to tropical America. They have leaves opposite of each other on the stem and heads of flowers that are borne along on long flower stalks or together in an open cluster. \n\nRead more here: https://www.britannica.com/plant/Cosmos-plant-genus"
            );
        }
    });

    //create slash command event (/crocus)
    bot.on_slashcommand([] (const dpp::slashcommand_t &event) {
        if(event.command.get_command_name() == "crocus") {
            event.reply(
                "Crocus, genus of about 75 low-growing cormose species of plants of the iris family (Iridaceae). Crocuses are native to the Alps, southern Europe, and the Mediterranean area and are widely grown for their cuplike blooms in early spring or fall. Spring-flowering plants have a long floral tube that allows the ovary to remain belowground, sheltered from climatic changes. \n\nRead more here: https://www.britannica.com/plant/Crocus"
            );
        }
    });

    //create slash command event (/sunflower)
    bot.on_slashcommand([] (const dpp::slashcommand_t &event) {
        if(event.command.get_command_name() == "sunflower") {
            event.reply(
                "Sunflower, (genus Helianthus), genus of nearly 70 species of herbaceous plants of the aster family (Asteraceae). Sunflowers are native primarily to North and South America, and some species are cultivated as ornamentals for their spectacular size and flower heads and for their edible seeds. The Jerusalem artichoke (Helianthus tuberosus) is cultivated for its edible underground tubers. \n\nRead more here: https://www.britannica.com/plant/sunflower-plant"
            );
        }
    });

    //create slash command event (/dandelion)
    bot.on_slashcommand([] (const dpp::slashcommand_t &event) {
        if(event.command.get_command_name() == "dandelion") {
            event.reply(
                "Dandelion, weedy perennial herb of the genus Taraxacum of the family Asteraceae, native to Eurasia but widespread throughout much of temperate North America. The most familiar species is T. officinale. \n\nRead more here: https://www.britannica.com/plant/dandelion"
            );
        }
    });

    //create slash command event (/jasmine)
    bot.on_slashcommand([] (const dpp::slashcommand_t &event) {
        if(event.command.get_command_name() == "jasmine") {
            event.reply(
                "Jasmine, (genus Jasminum), also spelled jessamine, genus of about 200 species of fragrant-flowered shrubs and vines of the olive family (Oleacea). The plants are native to tropical and to some temperate areas of the Old World. Several are cultivated as ornamentals. \n\nMost true jasmines have climbing branches without tendrils. The white, yellow, or rarely pink flowers are tubular with a flaring, lobed pinwheel-like form; some double-flowered varieties have been developed. The leaves can be evergreen or deciduous and usually are composed of two or more leaflets, although some species have simple leaves. The fruit in most species is a two-lobed black berry. \n\nRead more here: https://www.britannica.com/plant/jasmine-plant"
            );
        }
    });

    //create slash command event (/blossom)
    bot.on_slashcommand([] (const dpp::slashcommand_t &event) {
        if(event.command.get_command_name() == "blossom") {
            event.reply(
                "In botany, blossoms are the flowers of stone fruit trees (genus Prunus) and some other plants with a similar appearance that flower profusely for a period of time in spring. \n\nRead more here: https://en.wikipedia.org/wiki/Blossom"
            );
        }
    });

    //create slash command event (/lavender)
    bot.on_slashcommand([] (const dpp::slashcommand_t &event) {
        if(event.command.get_command_name() == "lavender") {
            event.reply(
                "Lavender, (genus Lavandula), genus of about 30 species of plants in the mint family (Lamiaceae), native to countries bordering the Mediterranean. Lavender species are common in herb gardens for their fragrant leaves and attractive flowers. The plants are widely cultivated for their essential oils, which are used to scent a variety of products. The dried flowers, for example, have been used in sachets to scent chests and closets, and the ancient Romans used lavender in their baths. Lavender is sometimes also used to flavour beverages and sweets and has a number of applications in herbal medicine. English lavender (Lavandula angustifolia), French lavender (L. stoechas), and woolly lavender (L. lanata) are among the most widely cultivated species. \n\nRead more here: https://www.britannica.com/plant/lavender"
            );
        }
    });

    //create slash command event (/rose)
    bot.on_slashcommand([] (const dpp::slashcommand_t &event) {
        if(event.command.get_command_name() == "rose") {
            event.reply(
                "A rose is either a woody perennial flowering plant of the genus Rosa, in the family Rosaceae, or the flower it bears. There are other three hundred species and tens of thousands of cultivars. They form a group of plants that can be erect shrubs, climbing, or trailing, with stems that are often armed with sharp prickles. Their flowers vary in size and shape and are usually large and showy, in colorus raning from white through yellows and reds. Most species are native to Asia, with smaller numbers native to Europe, North America, and northwestern Africa. Species, cultivars, and hybrids are all widely grown for their beauty and often are fragrant. Roses have acquired cultural significance in many societies. Rose plants range in size from compact, miniature roses, to climbers that can reach seven metres in height. Different species hybridize easily, and this has been used in the development of the wide range of garden roses. \n\nRead more here: https://en.wikipedia.org/wiki/Rose"
            );
        }
    });

    //create slash command event (/bellflower)
    bot.on_slashcommand([] (const dpp::slashcommand_t &event) {
        if(event.command.get_command_name() == "bellflower") {
            event.reply(
                "Bellflower, (genus Campanula), any of around 420 annual, perennial, and biennial herbs that compose the genus Campanula (family Campanulaceae). Bellflowers have characteristically bell-shaped, usually blue flowers, and many are cultivated as garden ornamentals. They are native mainly to norther temperate regions, Mediterranean areas, and tropical mountains. \n\nRead more here: https://www.britannica.com/plant/bellflower-plant"
            );
        }
    });

    //create slash command event (/primrose)
    bot.on_slashcommand([] (const dpp::slashcommand_t &event) {
        if(event.command.get_command_name() == "primrose") {
            event.reply(
                "Primrose, flowering plants of the genus Primula of the family Primulaceae, with 490-600 species, chiefly occurring in the Northern Hemisphere in cool or mountainous regions. The plants are low-growing, usually perennial herbs; a few are biennials. Most species grow 25 to 50 cm (10 to 20 inches) tall, but some are as short as 5 cm (2 inches) and others as tall as 1.2 metres (4 feet). Many species are cultivated for their attractive flowers. \n\nRead more here: https://www.britannica.com/plant/primrose-plant"
            );
        }
    });

    //create slash command event (/petunia)
    bot.on_slashcommand([] (const dpp::slashcommand_t &event) {
        if(event.command.get_command_name() == "petunia") {
            event.reply(
                "Petunia, genus of about 35 species of flowering plants in the nightshade family (Solanaceae), native to South America. The common garden petunia (Petunia xatkinsiana) is an ornamental plant whose showy trumpet-shaped flowers make it popular for summer flower beds and window boxes. \n\nRead more here: https://www.britannica.com/plant/petunia"
            );
        }
    });
    
    //create slash command event (/favouriteflowers)
    bot.on_slashcommand([] (const dpp::slashcommand_t &event) {
        if(event.command.get_command_name() == "favouriteflowers") {
            event.reply(
                "Flower Bot likes Irises, Tulips, Lilies, Blossoms, and Lavender flowers!"
            );
        }
    });

    //custom message (thank you flower bot)
    bot.on_message_create([&bot] (const dpp::message_create_t &event) {
        if(event.msg.content == "thank you flower bot" || event.msg.content == "thank you flower bot!" || event.msg.content == "thanks flower bot" || event.msg.content == "thanks flower bot!") {
            event.reply(
                "You're welcome. If you want to learn more about flowers, make sure you ask me for more information!"
            );
        }
    });

    //custom message (how reliable is flower bot)
    bot.on_message_create([&bot] (const dpp::message_create_t &event) {
        if(event.msg.content == "how reliable is flower bot" || event.msg.content == "how reliable is flower bot?" || event.msg.content == "is flower bot reliable" || event.msg.content == "is flower bot reliable?") {
            event.reply(
                "I'm as reliable as your google search. After all, the links and information I provide are from wiki/wikipedia related links, so please take caution and consideration when citing or using them. I am not responsible for any damages."
            );
        }
    });

    //custom message (flower complexity)
    bot.on_message_create([&bot] (const dpp::message_create_t &event) {
        if(event.msg.content == "flower complexity" || event.msg.content == "how complex are flowers" || event.msg.content == "how complex are flowers?" || event.msg.content == "are flowers complex" || event.msg.content == "are flower complex?") {
            event.reply(
                "Flowers are complex, and biologically speaking they have a lot going on inside them! :dna:"
            );
        }
    });

    //create embed (!flowerbot)
    bot.on_message_create([&bot] (const dpp::message_create_t &event) {
        if(event.msg.content == "!flowerbot") {
            dpp::embed embed1 = dpp::embed().
                set_color(dpp::colors::sti_blue).
                set_title("Flower Bot").
                set_url("https://github.com/alexwkleung/Flower-Bot").
                set_author("alexwkleung", "https://github.com/alexwkleung", "").
                set_description("A Discord bot that tells you basic scientific information and biological history about flowers.").
                set_timestamp(time(0));
                bot.message_create(dpp::message(event.msg.channel_id, embed1).set_reference(event.msg.id));
        }
    });

    //when bot is ready to be connected
    bot.on_ready([&bot] (const dpp::ready_t &event) {
        //run registered commands once when bot is connected. prevents commands from being 
        //run repeatedly if bot reconnects.
        if(dpp::run_once<struct register_bot_commands>()) {
            bot.global_command_create(dpp::slashcommand("Flowers", "Description about flowers", bot.me.id));
            bot.global_command_create(dpp::slashcommand("Iris", "Information about the Iris flower", bot.me.id));
            bot.global_command_create(dpp::slashcommand("Daisy", "Information about the Daisy flower", bot.me.id));
            bot.global_command_create(dpp::slashcommand("Tulip", "Information about the Tulip flower", bot.me.id));
            bot.global_command_create(dpp::slashcommand("Lily", "Information about the Lily flower", bot.me.id));
            bot.global_command_create(dpp::slashcommand("Orchid", "Information about the Orchid flower", bot.me.id));
            bot.global_command_create(dpp::slashcommand("Carnation", "Information about the Carnation flower", bot.me.id));
            bot.global_command_create(dpp::slashcommand("Freesia", "Information about the Freesia flower", bot.me.id));
            bot.global_command_create(dpp::slashcommand("Chrysanthemum", "Information about the Chrysanthemum flower", bot.me.id));
            bot.global_command_create(dpp::slashcommand("Gladiolus", "Information about the Gladiolus flower", bot.me.id));
            bot.global_command_create(dpp::slashcommand("Anemone", "Information about the Anemone flower", bot.me.id));
            bot.global_command_create(dpp::slashcommand("Daffodil", "Information about the Daffodil flower", bot.me.id));
            bot.global_command_create(dpp::slashcommand("Poppy", "Information about the Poppy flower", bot.me.id));
            bot.global_command_create(dpp::slashcommand("Buttercup", "Information about the Buttercup flower", bot.me.id));
            bot.global_command_create(dpp::slashcommand("Camellia", "Information about the Camellia flower", bot.me.id));
            bot.global_command_create(dpp::slashcommand("Cosmos", "Information about the Cosmos flower", bot.me.id));
            bot.global_command_create(dpp::slashcommand("Crocus", "Information about the Crocus flower", bot.me.id));
            bot.global_command_create(dpp::slashcommand("Sunflower", "Information about the Sunflower", bot.me.id));
            bot.global_command_create(dpp::slashcommand("Dandelion", "Information about the Dandelion flower", bot.me.id));
            bot.global_command_create(dpp::slashcommand("Jasmine", "Information about the Jasmine flower", bot.me.id));
            bot.global_command_create(dpp::slashcommand("Blossom", "Information about the Blossom flower", bot.me.id));
            bot.global_command_create(dpp::slashcommand("Lavender", "Information about the Lavender flower", bot.me.id));
            bot.global_command_create(dpp::slashcommand("Rose", "Information about the Rose flower", bot.me.id));
            bot.global_command_create(dpp::slashcommand("Bellflower", "Information about the Bellflower", bot.me.id));
            bot.global_command_create(dpp::slashcommand("Primrose", "Information about the Primrose flower", bot.me.id));
            bot.global_command_create(dpp::slashcommand("Petunia", "Information about the Petunia flower", bot.me.id));
            bot.global_command_create(dpp::slashcommand("FavouriteFlowers", "Flower Bot's favourite flowers", bot.me.id));
        }
    });

    //start cluster (bot)
    bot.start(dpp::st_wait);
}

int main() {
    FlowerBot flb;

    flb.bot();

    return 0;
}