# Flower Bot

A Discord bot that tells you basic scientific information and biological history about flowers. This bot could be useful for users that want to know general information about flowers. I created this to practice using the Discord API and CMake. I myself learned about various flowers while creating this bot, so reading about them can be an interesting read if you're bored.

Written in C++ using the [D++ (DPP) Discord API Library](https://github.com/brainboxdotcc/DPP).

WIP. I will try to add as many flowers as possible to the list of commands. Later on, I'll add more enhancements to make the bot useful and fun. 

# Install

Clone the repository.

```bash
git clone <SSH/HTTPS URL>
```

Change directory.

```bash
cd Flower-Bot
```

Create text file for API key.

```bash
# this directory is gitignored

touch src/key.txt
```

Add key to text file.

```txt
<your Discord API key>
```

Build using CMake.

You can use the VSCode CMake/CMake Tools extensions for an integrated CMake solution or run CMake from the CLI:

```bash
cmake --build Flower-Bot/build --config Debug --target all --
```

Run bot

You can use the VSCode CMake/CMake Tools extensions for an integrated CMake solution or run the output file from the CLI:

```bash
cd build

Flower-Bot/build/Flower-Bot
```

# Using the bot

**Slash commands:**

`/iris`

`/daisy`

`/tulip`

`/lily`

`/orchid`

`/carnation`

`/freesia`

`/chrysanthemum`

`/gladiolus`

`/anemone`

`/daffodil`

`/poppy`

`/buttercup`

`/cosmos`

`/crocus`

`/sunflower`

`/dandelion`

`/jasmine`

`/blossom`

`/lavender`

`/rose`

`/bellflower`

`/primrose`

`/petunia`

`/favouriteflowers`

**Custom messages (without the strings):**

`"thank you flower bot"`

`"how reliable is flower bot"`

`"flower complexity"`

**Embed commands:**

`!flowerbot`