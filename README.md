# Soul-like Game UE5

# Update note on 18 Aug 2022

Before I started it, I had no idea what an ER-like game required. It took me a long time to realize that you need a specific type of animation to make it feel like an ER game. After a difficult period, I am still unable to recreate the feeling of an ER (of course it is too hard, but it is my goal). Yeah, I made this repo to apply for some jobs, but to be honest, I'm not impressed with the outcome, so I doubt it will impress any recruiter.

So, what to do now?

I will extract the model and animation from ER, and put some of them in UE5. Re-create the combat. Yeah, it will take much time but it will produce much better result, I believe.

# Project

This project was created using both C++ and Blueprint in UE5 (5.0.3). The majority of the base classes are written in C++ and the details are updated using Blueprint.


The main character is Gideon from Paragon.

![Gideon](/Readme_Media/GideonScreenshot4-1920x1080-2e9d1192ac22760aa5c84ce2d43292c6.png)

# Demo Gameplay

Click to see a Youtube video

[![Gameplay](/Readme_Media/Gameplay_Screenshot.png)](https://youtu.be/-5BREUmPPAA)

# Project Features

+ Third-person Action Character Movement
+ Action System (similar to Gameplay Ability System in design)
    + Magic Projectile Attack
    + Roll to dodge (soul-like roll)
    + Turning player when attacking.
    + Animation notify system (mostly for attacking)
+ Lock on target: you could lock and switch target
    + Click to see a Youtube video
[![Lock On Target](/Readme_Media/Lock_On_Target.png)](https://youtu.be/Rbr8P9_QGOM)
+ AttributeComponent (Holding health etc.)
+ Heavy use of Events to drive UI and gameplay reactions.
+ Mix of C++ & Blueprint and how to combine these effectively.
+ AI
    + 2 types of Minion AIs with Behavior Trees: Melee and Ranged (Action list: Roam, See, Get hit react, Chase, Attack).
    + C++ & Blueprint Custom Behavior Trees Nodes
    + EQS for attack/cover locations by AI Powerups
+ UI elements for player attributes and projected widgets for enemy health.
+ UMG Main menu


# Game Assets

Most of assets are free contents on Unreal Marketplace. I also extract and put here some assets from DotA2 (will remove them later).

# Install 

Will add it later. I use 2 plugins so it could be a little bit different from normal build.
