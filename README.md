# My Moonlander Layout

Hello!

This repository contains the QMK layout I use on my ZSA Moonlander Mark I.

It also contains a little helper I made to easily integrate the keyboard with my work environment.

It is in very very early stages, I've started to play around custom QMK layouts recently, but I intend to organize this code as soon as I get some spare time.

If you have any suggestion of what could be added, I'd like to hear.

## Features

- Default Colemak layer
- Alternative QWERTY layer
- Many other helper layers
- HID integration
- Dedicated service for syncing keyboard states with system applications
- Helper script that mimic Mac OS tool xkbswitch, allowing applications to seamsly switch keyboard layers with a shell command
- Dedicated layer for League of Legends (see more below)

## HID Integration

- Bi-directional communication
- Modular structure
- Debuggable
- Fast as F*
- Highly inspired by these projects:
  - [mmalecki/qmk_rc](https://github.com/mmalecki/qmk_rc)
  - [zigotica/active-app-qmk-layer-updater](https://github.com/zigotica/active-app-qmk-layer-updater)

## Layer dance

![NVim Example](example/nvim.gif)

- The default layer is always Colemak
- If NVim window is active, the main layer is defined by the current mode
  - QWERTY for: Normal, Visual
  - Colemak for: Insert, Search, Command, Replace
- If League of Legends is launched its dedicated layer is automatically activated

## League of Legends MOD

![LoL Example](example/lol.gif)

- Automatically synchronizes with the active match
- Available skills
  - Only lights skill that has at least 1 level
  - Cooldowns are **not** indicated (in compliance with Riot terms)
  - TODO: change the color of the keys for each skill level
- Item slots
  - Only lights the keys of the slots which has a item
  - Cooldowns are **not** indicated (in compliance with Riot terms)
  - Blue for normal items
  - Light Blue for active items
  - Yellow for consumable items
- Both teams player indicator
  - Green for alive
  - Red for deas
  - Positions are sorted as shown in Tab
- Spell keys match the color of the icon at the slot
- Both teams dragon score indicator
  - Each of the thumb keys is a kill
  - The color of the key matcher the element of the killed dragon
  - The bigger key indicates the team got the Dragon Soul
  - TODO: animate when a team kills Elder Dragon or Baron
- Death animation
  - Everything goes red when you die (except for team indicators)
