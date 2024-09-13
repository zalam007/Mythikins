#include "../header/CutsceneManager.h"
#include "../header/GameplayMenu.h"

    void CutsceneManager::pressAnyKey(string& continueBTN){
        cout << endl << "Press any button to continue: ";
        cin >> continueBTN;
        cout << endl;
    }

    void CutsceneManager::MainMenu(){
        while(true) {
            int option;
            cout << "____________" << endl;
            cout << endl << "| MYTHIKIN |" << endl;
            cout << endl << "|__________|" << endl << endl;

            cout << "1. Start Game" << endl;
            cout << "2. Credits" << endl;
            cout << "3. Exit" << endl;

            cin >> option;

            switch (option)
            {
            case 1:
                // Start Game
                cout << endl << "Starting Game..." << endl << endl;
                this_thread::sleep_for(chrono::milliseconds(1000));
                break;
            case 2:
                // Credits
                cout << endl << "CREDITS" << endl;
                cout << "Developers: Axel Perez, Zami Alam, Dylon Wong, Jesse Nguyen" << endl;
                cout << "Assistant Programmer: Chad Gene Pritchett" << endl;
                cout << "Thanks For Playing!" << endl << endl;
                break;
            case 3:
                // Exit
                cout << endl << "Exiting Game..." << endl << endl;
                this_thread::sleep_for(chrono::milliseconds(1000));
                exit(0);

            default:
                cout << endl << "Invalid Option..." << endl << endl;
                break;
            }

            if(option == 1){
                break;
            }
        }
    }

    string CutsceneManager::IntroDreamScene(){
        cout << endl << "A fair-skinned professor stands before you, an eccentric and wise figure with a spark in his eye." << endl << "The gentle breeze from the ocean rustles his papers as he begins to speak." << endl << endl;
        cout << "\"Welcome to the enchanting world of Mythikin!" << endl;

        pressAnyKey(continueBTN);

        cout << "In this land of wonder and mystery, creatures known as Mythikin roam the wilds, each possessing unique abilities and traits." << endl << "From the bustling shores of Isla Mystica to the uncharted territories beyond, the world is teeming with adventure and discovery." << endl;
        cout << "As you explore, you’ll encounter a diverse array of Mythikin, each with their own story to tell." << endl << "Some may become loyal companions, while others will challenge your wits and courage. The journey ahead is filled with trials and triumphs, secrets and surprises." << endl;

        pressAnyKey(continueBTN);

        cout << "Prepare yourself for an epic quest where the ordinary becomes extraordinary, and the mundane transforms into the magical." << endl << "The world of Mythikin awaits—are you ready to uncover its mysteries?" << endl;
        cout << "The professor smiles warmly, the sound of waves crashing in the distance as he prepares to guide you on your journey.\"" << endl << endl;

        pressAnyKey(continueBTN);

        cout << "The professor proceeds to look from his script, his eyes widening." << endl;
        cout << "\"Hold on. Who are you?\"" << endl << endl;

        //Player Name
        cin.ignore(256, '\n');
        string name;
        string confirm;
        while (true) {
            cout << "Please enter your name: ";
            getline(cin, name);
            cout << "\"You're name is " << name << "?\" (yes/no): ";
            getline(cin, confirm);
            if (confirm == "yes") { break; }
            else if (confirm == "no"){cout << "\"You forgot your name? Let's try again.\"" << endl;}
            else{cout << "\"What are you saying? What is your name?\"" << endl;}
        }

        //Waking up (Story Intro)
        cout << endl << "\"Welcome, " << name << "!\"" << endl;
        cout << "\"I was not expecting you. I was expecting someone else. But you will do.\"" << endl;
        cout << "\"However, I need you to do one thing for me...\"" << endl;

        pressAnyKey(continueBTN);

        cout << "\"Wake up.\"" << endl;

        pressAnyKey(continueBTN);

        cout << "\"Wake up!\"" << endl;

        pressAnyKey(continueBTN);
        
        cout << "\"Wake up!!\"" << endl;

        pressAnyKey(continueBTN);

        cout << "\"Wake up!!!\"" << endl;

        pressAnyKey(continueBTN);

        return name; // Return Player Name used for the entire game!
    }

    void CutsceneManager::IntroWakeUpScene(string& name){
        cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "You jolt awake, still in a daze. Your mother stands at the stair's railing. Her gaze piercing your squinting eyes." << endl;
        cout << "\"" << name << ", WAKE UP!\"" << endl << endl;

        pressAnyKey(continueBTN);

        cout << "\"It is almost noon, and you are still in bed! This has to stop." << endl << "You're already 30 years old, but all you do is play Valorant, Tekken, and watch looksmaxxing edits on TikTok!" << endl;
        cout << "Why can't you be like your brother? I am tired, and I am fed up with seeing you waste your life away. " << endl;
        cout << "You should be more like your younger brother Jesse. Jesse's only 18, but he already has a 6-figure job as a software developer at Mythicorp and the sharpest jawline known to man." << endl;

        pressAnyKey(continueBTN);

        cout << "Do something with your life! Be a programmer like your brother, get a job working in fast food, or become a Mythikin master—just do something, I don’t care!" << endl;
        cout << "Just be someone and do something! I know you can do it if you just put in the effort. Get out of this basement and start making something of yourself." << endl;
        cout << "I can not keep watching you throw your life away like this.\"" << endl;

        pressAnyKey(continueBTN);

        cout << endl << "She storms up the stairs and out of the room, leaving you alone with your thoughts. The silence in the basement feels heavier than usual." << endl;
        cout << endl << "You take a deep breath and get out of bed." << endl << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
    }

    void CutsceneManager::HomeScene(string& name){
        cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "The tension still lingers from downstairs. Your mother's back is turned from you as she is preparing Munchi-cakes." << endl;
        cout << "The fantastic smell spreading across the living room. Suddenly, your mother discovers your presence." << endl;

        pressAnyKey(continueBTN);

        cout << "\"Oh, " << name << "! I didn't see you there.\"" << endl;
        cout << "\"I just recieved a message from Professor Alder. He asked to meet you.\"" << endl;
        cout << "\"He is at his lab. The metal building in the center of town.\"" << endl << endl;
        cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    }

    void CutsceneManager::ProfessorAlderLabScene(string& name){
        cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "You push open the heavy metal door of Professor Alder’s lab, greeted by the familiar scent of chemicals and the faint hum of fluorescent lights." << endl;
        cout << "The lab is a cluttered haven of scientific curiosity: beakers filled with colorful liquids bubble away on dusty shelves, and stacks of papers are piled high next to a well-worn desk." << endl; 
        cout << "A large chalkboard, smudged with scribbled equations and diagrams, dominates one wall. Personnel are scrambling around the room." << endl;
        cout << "In the center of the room, Professor Alder, a disheveled yet kind-faced man in his late fifties, is hunched over a microscope, mumbling to himself." << endl;

        pressAnyKey(continueBTN);

        cout << "He looks up, his glasses sliding down his nose, and his face lights up with a mix of relief and enthusiasm. \"Ah, there you are!\" Alder exclaims, straightening up and brushing his lab coat. \"I’m so glad you came.\"" << endl;
        cout << "\"I need your help with something. You see, I’ve been studying the Mythikin of this region for years, and I’ve made a groundbreaking discovery.\"" << endl;
        cout << "\"There is a legendary Mythikin lurking our world. I know it!\"" << endl;

        pressAnyKey(continueBTN);

        cout << "\"I need you to find it. I need you to find the Mythikin that I have been searching for.\"" << endl;
        cout << "One of the professors, Professor Spruce, chimes in. \"We have gone over this already boomer! IT DOESN'T EXIST! This is why you were put on Mythikin dung cleanup. It might clean your mess of a mind too.\" " << endl;
        cout << "The other professors snicker." << endl;

        pressAnyKey(continueBTN);

        cout << "Professor Alder looks at you with a pleading look. \"Please, " << name << ". I need you to find it.\"" << endl;
        cout << "\"I would ask Jesse but I can't get a hold of him. Not to mention this is a favor to your mother...\"" << endl;
        cout << "\"However, I believe you can do it!\"" << endl;

        pressAnyKey(continueBTN);

        cout << "\"According to my research. The legendary Mythikin will only show itself to the most powerful Mythic Master.\"" << endl;
        cout << "\"To face the three standing Mythic Masters you'll need to go to Mythic Tower in Los Solara.\"" << endl;
        cout << "\"But, they wouldn't face anyone below 3 Medallions. The rewards for beating Academies.\"" << endl;
        cout << "\"There's three. One in Dunefall, Avalora Bay, and Ojada.\"" << endl;
        cout << "\"Find the academies in those cities and beat the Mentors to get their Medallion.\"" << endl;

        pressAnyKey(continueBTN);

        cout << "\"I have a Mythidex for you. It is a device that will help you track and record the Mythikin you encounter.\"" << endl;
        cout << "\"I also have a few Mythicubes for you. It is a device that will help you capture the Mythikin you encounter.\"" << endl;

        cout << "\"To get you started, you'll need a Mythikin! These are incredibly rare, yet loyal Mythikin. Your pick.\"" << endl << endl;

        pressAnyKey(continueBTN);

        //Choose your starter
        cout << endl << "-------------------------------------------------------------------------------------" << endl;

        cout << "You are given a choice of three Mythikin: (Warning: You can only choose one!)" << endl;
        cout << "1. " << mythikins["Blazehoof"]->getName() << endl;
        cout << "2. " << mythikins["Tidefin"]->getName() << endl;
        cout << "3. " << mythikins["Stemlet"]->getName() << endl;

        int choice;
        while(true) {
            cout << "Choose a Mythikin: ";
            cin >> choice;
            if(choice >= 1 && choice <= 3) {
                break;
            }
            else {
                cout << "Invalid choice. Please choose a valid option." << endl;
            }
            cin.clear();
            cin.ignore(256, '\n');
        }

        switch(choice) {
            case 1:
                player.addMythikin(*mythikins["Blazehoof"]);
                cout << "You chose " << mythikins["Blazehoof"]->getName() << "!" << endl;
                break;
            case 2:
                player.addMythikin(*mythikins["Tidefin"]);
                cout << "You chose " << mythikins["Tidefin"]->getName() << "!" << endl;
                break;
            case 3:
                player.addMythikin(*mythikins["Stemlet"]);
                cout << "You chose " << mythikins["Stemlet"]->getName() << "!" << endl;
                break;
        }

        cout << "Would you like to give your Mythikin a nickname? (yes/no): ";
        string nickname;
        string confirm;
        cin.ignore(256, '\n');
        while (true) {
            getline(cin, confirm);
            if (confirm == "yes") {
                cout << "Enter a nickname: ";
                getline(cin, nickname);
                player.getTeam().getSlot(0).setName(nickname);
                break;
            }
            else if (confirm == "no") {
                break;
            }
            else {
                cout << "Invalid choice. Please choose a valid option." << endl;
            }
            cin.clear();
        }

        cout << endl << "-------------------------------------------------------------------------------------" << endl << endl;

        cout << endl << "\"I am sure " << player.getTeam().getSlot(0).getName() << " and you will be the best of friends.\"" << endl;
        cout << "\"Now, go out there and find the legendary Mythikin!\"" << endl;
        cout << "Professor Alder hands you the Mythidex and Mythicubes. \"Good luck, " << name << "!\"" << endl;

        cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;

        cout << "New locations are now available in the gameplay menu!" << endl << endl;
    }

    void CutsceneManager::DunefallAcademyScene(string& name){
        cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

        cout << "The heavy stone doors of Dunefall’s Academy groan open as you step inside, immediately blasted by the oppressive heat." << endl;
        cout << "The walls shimmer with the glow of molten lava flowing through channels carved into the stone, casting flickering shadows across the sand-covered floor." << endl;
        cout << "It feels less like an Academy and more like the heart of a volcano." << endl;

        pressAnyKey(continueBTN);

        cout << "At the far end of the room, standing with his back to you, is Ignatius Kael." << endl;
        cout << "He’s hammering a glowing blade on an anvil, the clanging echoing through the chamber." << endl;
        cout << "Sparks fly with each strike, painting the scene with flashes of light." << endl;

        pressAnyKey(continueBTN);

        cout << "His presence is intimidating even from a distance—broad-shouldered, covered in battle scars, and exuding the kind of heat you can feel." << endl;
        cout << "Without turning around, he speaks, his voice as rough as the desert winds." << endl;
        cout << "\"Another nobody comes wandering in from the dunes, huh?\"" << endl;

        pressAnyKey(continueBTN);

        cout << "He lets out a sharp exhale, placing the hammer down. \"Must be desperate for that Ash Medallion.\"" << endl;
        cout << "He finally turns to face you, his dark, fiery eyes locking onto you with a piercing intensity." << endl;
        cout << "There’s a faint smirk on his face, but it’s more bemused than welcoming." << endl;

        pressAnyKey(continueBTN);

        cout << "\"You don’t look like much,\" he says, taking a few steps forward. \"Most people who stand where you’re standing right now… they’re already regretting it.\"" << endl;
        cout << "Ignatius crosses his arms, the flames dancing on his tattoos seeming to flare up as he sizes you up." << endl;
        cout << "\"But I am a fair man. You want the Ash Medallion? You’ve got to earn it. No handouts here, not in Dunefall.\"" << endl;

        pressAnyKey(continueBTN);

        cout << "He pulls two Mythicubes from his belt, the air immediately heating up as they begin to glow in his hands." << endl;
        cout << "\"You think you can just wander in off the streets and take what real warriors fight for? Let’s see if you can even handle the flames.\"" << endl;

        pressAnyKey(continueBTN);

        cout << "Ignatius smirks again, more amused this time." << endl;
        cout << "\"Go ahead, nobody. Show me if you’re worth my time—or if the desert’s just gonna swallow you whole like the rest.\"" << endl;
        cout << "The heat of the arena rises as the flames swirl around you, and Ignatius steps back, arms crossed, ready to watch the fire determine your fate." << endl;

        pressAnyKey(continueBTN);

        cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

        chrono::seconds(1);
    }

    void CutsceneManager::DunefallAcademyEndScene(string& name){
        cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

        cout << "Ignatius stands amidst the cooling ashes, his fiery aura dimming to a mere flicker." << endl;

        pressAnyKey(continueBTN);

        cout << "\"Not bad,\" he says with a gruff chuckle, his voice raspy but laced with grudging respect." << endl;
        cout << "He approaches, each step sending small puffs of smoke into the air, and retrieves the **Ash Medallion** from a nearby pedestal." << endl;

        pressAnyKey(continueBTN);

        cout << "The medallion is a dark, molten stone, cool now but still warm to the touch, etched with flame patterns." << endl;
        cout << "\"You’ve earned this,\" Ignatius says, handing it to you. \"But remember, fire’s not just about destruction. It’s about forging something new.\"" << endl;

        pressAnyKey(continueBTN);

        cout << "He pauses, his eyes narrowing with a hint of a smile. \"You showed you can withstand the heat. Don’t forget the lesson—it’s not just about surviving, but what you make of the ashes.\""<< endl;
        cout << "With a nod, Ignatius steps back, his fiery presence retreating as the room cools." << endl;

        pressAnyKey(continueBTN);

        cout << "The **Ash Medallion** in hand, Ignatius’s words echo, a reminder of the trials and the strength forged in the flames." << endl;

        pressAnyKey(continueBTN);

        cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    }

    void CutsceneManager::OjadaAcademyScene(string& name){
        cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

        cout << "You step into the Soil Academy, immediately greeted by the soothing scent of fresh earth and blooming flowers." << endl;
        cout << "The air is cooler here, a stark contrast to the blazing desert heat of Dunefall." << endl;
        cout << "The walls of the Academy are alive—covered in twisting vines, moss, and ancient trees that grow impossibly through the stone itself." << endl;
        cout << "Light filters through gaps in the ceiling where roots from towering trees above the Academy let in rays of sunlight," << endl;
        cout << "casting a peaceful, dappled glow across the soft, grass-covered floor." << endl;

        pressAnyKey(continueBTN);

        cout << "At the center of the room, on a circular stone platform surrounded by lush greenery, sits Sylvaine Marrowood, cross-legged in a meditative pose." << endl;
        cout << "She’s perfectly still, eyes closed, as if she’s listening to something far beyond what any ordinary person can hear." << endl;
        cout << "The room feels impossibly quiet, like the earth itself is holding its breath in her presence." << endl;

        pressAnyKey(continueBTN);

        cout << "Without opening her eyes, Sylvaine speaks, her voice calm and melodic, yet full of awareness." << endl;
        cout << "\"I felt you coming long before you arrived, traveler,\" she says softly." << endl;
        cout << "\"The earth whispered your name, carried on the wind and through the roots of the trees.\"" << endl;

        pressAnyKey(continueBTN);

        cout << "She slowly rises to her feet with the grace of flowing water, her long, vine-woven hair rustling softly as she moves." << endl;
        cout << "Sylvaine turns to face you, her sharp green eyes now open, and she offers you a serene smile." << endl;
        cout << "\"You’ve come seeking the Soil Medallion,\" she says, her tone thoughtful." << endl;
        cout << "\"But to seek is one thing, and to be truly connected to nature is another.\"" << endl;

        pressAnyKey(continueBTN);

        cout << "Her bare feet step lightly across the mossy floor as she moves closer, gesturing to the vibrant plants and flowers that seem to respond to her presence." << endl;
        cout << "\"Nature doesn’t rush, yet everything is accomplished in its time." << endl;
        cout << "You, too, must find balance if you are to prove yourself here.\"" << endl;

        pressAnyKey(continueBTN);

        cout << "The air thickens, and the earth beneath your feet trembles gently as if the ground itself is preparing for battle." << endl;
        cout << "\"I will not overpower you with force. No, that is not the way of nature." << endl;

        pressAnyKey(continueBTN);

        cout << "Instead, we will see if you can adapt, grow, and flourish—or be swallowed by the wilds.\"" << endl;
        cout << "Sylvaine stands calmly beside them, her hands resting gently at her sides." << endl;
        cout << "\"Remember, the soil is both cradle and grave,\" she says with a peaceful smile." << endl;

        pressAnyKey(continueBTN);

        cout << "\"Let nature guide you, or it will consume you.\"" << endl;
        cout << "The gentle hum of nature around you becomes a pulse, rhythmic, like the heartbeat of the world itself, as the battle begins." << endl;

        pressAnyKey(continueBTN);

        cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    }

    void CutsceneManager::OjadaAcademyEndScene(string& name){
        cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

        cout << "Sylvaine remains still, her expression calm, as if the battle never disturbed her." << endl;
        cout << "\"Impressive,\" she says with a faint smile. \"You fought with patience, not haste.\"" << endl;

        pressAnyKey(continueBTN);
        
        cout << "She approaches, her steps light on the mossy ground." << endl;
        cout << "\"Nature thrives in balance, and you’ve shown you understand that.\" Sylvaine pulls out the **Soil Medallion**, its design etched with vines and roots." << endl;

        pressAnyKey(continueBTN);
        
        cout << "As she places it in your hand, the weight feels significant." << endl;
        cout << "\"Take this, but know it’s more than a symbol,\" she adds quietly, her eyes thoughtful. \"It’s a reminder of what endures, what bends, and what breaks.\"" << endl;

        pressAnyKey(continueBTN);

        cout << "Stepping back, she gives a small nod. \"Go forward with that understanding, and let the roots you’ve planted carry you far.\"" << endl;
        cout << "With the **Soil Medallion** in hand, Sylvaine’s words lingering in the air like a soft breeze." << endl;

        pressAnyKey(continueBTN);

        cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    }

    void CutsceneManager::AvaloraBayAcademyScene(string& name){
        cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

        cout << "You step into the Aqua Academy, immediately enveloped by a soothing, oceanic atmosphere." << endl;
        cout << "The walls of the academy are lined with shimmering mosaics of aquatic scenes—waves crashing, schools of fish darting, and coral reefs blooming." << endl;
        cout << "The floor is a transparent, crystal-clear surface, beneath which a gentle current flows, creating the illusion of walking on water." << endl;

        pressAnyKey(continueBTN);

        cout << "At the center of the room, on a platform that appears to float above a tranquil pool, stands Maris Tidecaller." << endl;
        cout << "She is seated in a meditative pose, her dark blue hair cascading around her like the waves of the sea, her eyes closed in serene concentration." << endl;

        pressAnyKey(continueBTN);

        cout << "As you approach, Maris opens her eyes, which gleam like polished sea glass, and her serene expression shifts to one of welcoming calm." << endl;
        cout << "\"Welcome,\" she says softly, her voice a soothing melody. \"I’ve been expecting you, traveler.\""<< endl;

        pressAnyKey(continueBTN);

        cout << "She rises gracefully from her platform, her robes flowing like liquid silk as she moves." << endl;
        cout << "\"The ocean has shared many secrets with me,\" she continues, her gaze steady and understanding. \"And now, it is time for you to learn from its depths.\""<< endl;

        pressAnyKey(continueBTN);

        cout << "Maris gestures to the pool beneath the platform. The water swirls gently, forming shapes that resemble Mythikin readying for battle." << endl;
        cout << "\"To earn the Liquid Medallion, you must embrace the flow of battle,\" she instructs, her voice calm yet firm. \"Adapt to the currents, and let them guide you.\""<< endl;

        pressAnyKey(continueBTN);

        cout << "She steps back, her presence as tranquil as the water around her, and watches as she readies for the challenge ahead." << endl;
        cout << "\"Let us see how well you can navigate the waves.\"" << endl;
        cout << "The water shimmers, the battle beginning with the serene yet formidable guidance of Maris Tidecaller in the background." << endl;

        pressAnyKey(continueBTN);

        cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    }

    void CutsceneManager::AvaloraBayAcademyEndScene(string& name){
        cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

        cout << "Maris stands at the edge of the pool, her expression serene yet knowing." << endl;
        cout << "\"You have shown great adaptability and grace in battle,\" she says, her voice like the lapping of waves on the shore." << endl;

        pressAnyKey(continueBTN);

        cout << "She approaches, the water beneath her feet parting like a living path." << endl;
        cout << "\"The ocean is vast and ever-changing, but you have proven you can navigate its depths with skill and wisdom.\"" << endl;
        cout << "Maris retrieves the **Liquid Medallion** from the water, its surface shimmering like sunlight on the waves." << endl;

        pressAnyKey(continueBTN);

        cout << "She places it in your hand, the cool metal a stark contrast to the warmth of her touch." << endl;
        cout << "\"Take this as a token of your journey through the tides,\" she says, her eyes reflecting the depths of the sea." << endl;

        pressAnyKey(continueBTN);

        cout << "With a nod, she steps back, her presence as calming as the ocean itself." << endl;
        cout << "\"May the Liquid Medallion guide you through the currents of your path, traveler.\"" << endl;
        cout << "The **Liquid Medallion** in hand, Maris’s words echoing like the ebb and flow of the tide." << endl;

        pressAnyKey(continueBTN);

        cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    }

    void CutsceneManager::FightingJax(string& name){
        cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

        cout << "You step into the grand arena, a vast space illuminated by shifting lights that create a dramatic, almost cinematic atmosphere. The anticipation is palpable as the arena’s temperature fluctuates between searing heat and cool digital ambiance." << endl;

        pressAnyKey(continueBTN);

        cout << "From the shadows, Magma Master Jax strides forward, his figure framed by the glow of molten lava. He spins an invisiable in his hand." << endl;
        cout << "\"Well, well, well,\" Jax drawls in a gravelly voice, tipping his hat. \"Looks like we’ve got a real contender here. I hope you’re ready to feel the burn.\""<< endl;

        pressAnyKey(continueBTN);

        cout << "At the same time, Aqua Master Dean steps into view, surrounded by floating holograms and shimmering data streams. His modern, techy attire contrasts sharply with Jax’s rugged appearance." << endl;
        cout << "\"Impressive progress,\" Dean says with a sly grin. \"But now you’ll need more than just guts. Prepare to navigate through the complexities of code and data.\""<< endl;

        pressAnyKey(continueBTN);

        cout << "Finally, Flora Master Zane emerges with a charismatic flair, holding a director’s megaphone and dressed in stylish, cinematic attire." << endl;
        cout << "\"And action!\" Zane announces with theatrical enthusiasm. \"You’ve reached the final act, and it’s going to be a blockbuster performance! Ready to face your role in this epic finale?\""<< endl;

        pressAnyKey(continueBTN);

        cout << "The three Mythic Masters exchange knowing glances. With a dramatic wave of his hand, Master Jax steps forward." << endl;
        cout << "\"I'll put this rough rider down.\"" << endl;

        pressAnyKey(continueBTN);

        cout << "The arena’s atmosphere becomes unrelentingly hot and flames blazimg around." << endl;

        cout << "Master Jax raises his arm, fingers pointing, \"BANG!\"" << endl;

        pressAnyKey(continueBTN);

        cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    }

    void CutsceneManager::FightingDean(string& name){
        cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

        cout << "You manage to outmaneuver the fiery cowboy. Jax stumbles back, his flames in the background flickering wildly before finally extinguishing." << endl;
        cout << "\"Well, I'll be...\" Jax mutters, wiping sweat from his brow. \"You’ve got some grit, I'll give ya that. But don’t get too cocky, partner.\""<< endl;
        cout << "He tips his hat one last time and steps back, the molten ground cooling as your attention turns." << endl;

        pressAnyKey(continueBTN);

        cout << "The arena’s atmosphere shifts dramatically, becoming sleek and digital as the lights dim and holograms reappear. Master Dean steps forward, his tech-savvy persona immediately taking center stage." << endl;
        cout << "\"Nice work against Jax,\" Master Dean says with a nod, his voice cool and calculating." << endl;
        cout << "Dean gestures, and the arena's screens display into a dynamic, water-themed labyrinth." << endl;

        pressAnyKey(continueBTN);

        cout << "\"Compile ./Battle!\"" << endl;

        cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    }

    void CutsceneManager::FightingZane(string& name){
        cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

        cout << "The water motifs and digital displays fade as Dean steps back, his expression one of impressed resignation." << endl;
        cout << "\"Looks like you’ve managed to stay afloat,\" Dean remarks with a nod."<< endl;

        pressAnyKey(continueBTN);

        cout << "As Dean retreats, the arena undergoes a dramatic transformation." << endl;
        cout << "Suddenly, the lights go out." << endl;

        pressAnyKey(continueBTN);

        cout << "Stagelights activate revealing that the environment morphed into a vibrant, cinematic setting with elaborate props and a dramatic stage." << endl;
        cout << "From the center of this grand film set, Master Zane makes his presence. He looks out at you with theatrical enthusiasm." << endl;
        cout << "Zane announces with flair, his voice echoing through the arena. \"You’ve made it to the final act, and it’s time for the climax!\""<< endl;

        pressAnyKey(continueBTN);

        cout << "The arena is a bustling film set, complete with dramatic lighting, camera angles, and the Mythikin ready for their close-ups." << endl;
        cout << "With a grand gesture, Zane invites you to step into the spotlight." << endl;

        pressAnyKey(continueBTN);

        cout << "\"Action!\"" << endl;

        pressAnyKey(continueBTN);

        cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    }

    void CutsceneManager::JexseeStopsPlayerScene(string& name){
        cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "You reach the grand gate." << endl;
        cout << "The Gate of Sun and Shore towers above you, gleaming in the sunlight, with waves from Vastblue Shore crashing ominously beyond." << endl;
        cout << "The carvings on the gate seem to come alive, depicting ancient battles between sea and sky. But before you can take it all in, a short figure approaches" << endl;

        pressAnyKey(continueBTN);

        cout << "Jexsee, the gate guard, twirls his baton lazily and grins. \"Whoa there, pal. This is the Gate of Sun and Shore, not a walk in the park to Los Solara." << endl;
        cout << "You got your three medallions?\"" << endl;

        pressAnyKey(continueBTN);

        cout << "Jexsee’s grin widens. \"No medallions, no entry. That’s the rule. Sorry I don't make the rules. Ha! or do I?\"" << endl;
        cout << "With a dramatic wave of his baton, Jexsee steps aside. \"Come back when you’re actually ready, champ. Until then, this gate stays closed.\"" << endl;

        pressAnyKey(continueBTN);

        string confirm;
        cout << "Would you like to punch the guard? (yes/no): ";
        cin.ignore(256, '\n');
        while (true) {
            getline(cin, confirm);
            if (confirm == "yes") {
                cout << "As Jexsee leans in with another smug comment, you snap, throwing a punch that lands squarely on his helmet with a CLANG. His helmet spins backward, and he stumbles, flailing wildly. “Whoa! What just—!?\"" << endl;
                cout << "Disoriented, he fumbles to remove the helmet, his hair a mess. \"Alright, alright, you got me!\" he says, still grinning. \"But guess what? No medallions, still no entry.\"" << endl;
                cout << "He squirms back to his post. You notice a few shiny coins on the ground. Must've fallen from his pocket after your wallop!" << endl << endl;

                pressAnyKey(continueBTN);

                cout << "You got 100 coins!" << endl;
                player.addCoins(100);

                pressAnyKey(continueBTN);

                break;
            }
            else if (confirm == "no") {
                cout << "You leave the guard alone without a fuss." << endl;
                cout << "Jexsee chuckles. \"I see I annoyed you.\"" << endl;
                cout << "\"As reconcilation, so you do not punch me... here is a Mythicube!\"" << endl;

                pressAnyKey(continueBTN);

                cout << "You got a Mythicube!" << endl;
                player.addBattleItem(static_cast<BattleItem*>(items["Mythicube"]));
                cout << "\"Now scram!\"" << endl;
                cout << "With pride, Jexsee struts back to his post." << endl;

                pressAnyKey(continueBTN);

                break;
            }
            else {
                cout << "Invalid choice. Please choose a valid option." << endl;
            }
        }
        

        cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
        cout << "Come back when you have beaten the three Academies!" << endl << endl;
    }

    void CutsceneManager::JexseeLetsPlayerGoScene(string& name){
        cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "You return to the Gate of Sun and Shore, the three gleaming medallions clinking at your side. The towering gate looks just as imposing, but this time, you feel different. Ready." << endl;
        cout << "Jexsee, once again slouched against the gate, notices you approaching. He straightens up, twirling his baton with his usual flair. \"Well, well, look who’s back." << endl;
        cout << "Here to collect your complimentary ‘Sorry, you still can’t pass’ speech?\" He chuckles, clearly thinking he’s hilarious." << endl;

        pressAnyKey(continueBTN);

        cout << "But as you step closer, you casually reveal the three medallions. Jexsee’s eyes widen, the baton slipping from his hand and clattering to the ground. \"Wait... what? You... you actually got them?\"" << endl;
        cout << "He scrambles over, inspecting the medallions like they’re rare treasures. \"No way! You actually did it!\"" << endl;
        cout << "He lets out a low whistle, clearly impressed. \"Well, I’ll be... Looks like you’re officially one of the big shots now. Guess I can’t stop you anymore.\" He steps aside with a dramatic bow." << endl;
        cout << "\"Unfortunatly, this gate takes some time to open so leave and come back. Ok?\"" << endl;
        cout << "\"Welcome to Vastblue Shore! Try not to get eaten by anything, yeah?\"" << endl;

        pressAnyKey(continueBTN);

        cout << "The gate creaks open, revealing a world of endless possibilities beyond. You take a deep breath, feeling the salty sea breeze on your face." << endl;
        cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
    }