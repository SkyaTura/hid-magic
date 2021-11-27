#define  LOL_LAYER           2
#define  LOL_SIZE_KEY        33
#define  LOL_SIZE_STATE      33
#define  CL_OFF              {   0,    0,    0    }
#define  CL_NEUTRAL          {   15,   15,   15   }
#define  CL_TRANSPARENT      {   -1,   -1,   -1   }
#define  CL_PLAYER_EMPTY     {   0,    255,  0    }
#define  CL_PLAYER_ALIVE     {   0,    255,  0    }
#define  CL_PLAYER_DEAD      {   255,  0,  0    }
#define  CL_ITEM_EMPTY       {   0,    0,    0    }
#define  CL_ITEM             {   0,    0,    255  }
#define  CL_ITEM_USABLE      {   0,    255,  255  }
#define  CL_ITEM_CONSUMABLE  {   255,  255,  0    }
#define  CL_SKILL_EMPTY      {   0,    0,    0    }
#define  CL_SKILL_LVL_1      {   255,  0,    255  }
#define  CL_SKILL_LVL_2      {   255,  0,    255  }
#define  CL_SKILL_LVL_3      {   255,  0,    255  }
#define  CL_SKILL_LVL_4      {   255,  0,    255  }
#define  CL_SKILL_LVL_5      {   255,  0,    255  }
#define  CL_SKILL_LVL_6      {   255,  0,    255  }
#define  CL_SPELL_FALLBACK   {   255,  255,  0    }

#define lol_get_color(color) (RGB) { .r = color[0], .g = color[1], .b = color[2] }

int lol_layer_keymap[LOL_SIZE_KEY] = {
   -2, // 0 Game Running
   -2, // 1 Is Alive
   6,  // 2 Ability Q
   11, // 3 Ability W
   16, // 4 Ability E
   21, // 5 Ability R
   5,  // 6 Item 1
   10, // 7 Item 2
   15, // 8 Item 3
   13, // 9 Item 4
   18, // 10 Item 5
   23, // 11 Item 6
   0,  // 12 Trinket
   4,  // 13 Order Player 1
   9,  // 14 Order Player 2
   14, // 15 Order Player 3
   19, // 16 Order Player 4
   24, // 17 Order Player 5
   40, // 18 Chaos Player 1
   45, // 19 Chaos Player 2
   50, // 20 Chaos Player 3
   55, // 21 Chaos Player 4
   60, // 22 Chaos Player 5
   17, // 23 Spell D
   22, // 24 Spell F
   32, // 25 Order 1st Dragon
   33, // 26 Order 2nd Dragon
   34, // 27 Order 3rd Dragon
   35, // 28 Order Soul Dragon
   68, // 29 Chaos 1st Dragon
   69, // 30 Chaos 2nd Dragon
   70, // 31 Chaos 3rd Dragon
   71  // 32 Chaos Soul Dragon
};
// 3 2 1 4
// 2 3 0 1
int lol_layer_features[LOL_SIZE_KEY] = {
   -2, // 0 Game Running
   -2, // 1 Is Alive
   1,  // 2 Ability Q
   1,  // 3 Ability W
   1,  // 4 Ability E
   1,  // 5 Ability R
   2,  // 6 Item 1
   2,  // 7 Item 2
   2,  // 8 Item 3
   2,  // 9 Item 4
   2,  // 10 Item 5
   2,  // 11 Item 6
   2,  // 12 Trinket
   3,  // 13 Order Player 1
   3,  // 14 Order Player 2
   3,  // 15 Order Player 3
   3,  // 16 Order Player 4
   3,  // 17 Order Player 5
   3,  // 18 Chaos Player 1
   3,  // 19 Chaos Player 2
   3,  // 20 Chaos Player 3
   3,  // 21 Chaos Player 4
   3,  // 22 Chaos Player 5
   4,  // 23 Spell D
   4,  // 24 Spell F
   5, // 25 Order 1st Dragon
   5, // 26 Order 2nd Dragon
   5, // 27 Order 3rd Dragon
   5, // 28 Order Soul Dragon
   5, // 29 Chaos 1st Dragon
   5, // 30 Chaos 2nd Dragon
   5, // 31 Chaos 3rd Dragon
   5 // 32 Chaos Soul Dragon
};

int lol_state[LOL_SIZE_STATE] = {
   0, // Game running (0 = no, 1 = yes)
   0, // Is dead (0 = no, 1 = yes)
   0, // Ability Q (0 = unavailable, >1 current ability level)
   0, // Ability W (0 = unavailable, >1 current ability level)
   0, // Ability E (0 = unavailable, >1 current ability level)
   0, // Ability R (0 = unavailable, >1 current ability level)
   0, // Item 1 (0 = unavailable, 1 = bought, 2 = canUse, 3 = consumable)
   0, // Item 2 (0 = unavailable, 1 = bought, 2 = canUse, 3 = consumable)
   0, // Item 3 (0 = unavailable, 1 = bought, 2 = canUse, 3 = consumable)
   0, // Item 4 (0 = unavailable, 1 = bought, 2 = canUse, 3 = consumable)
   0, // Item 5 (0 = unavailable, 1 = bought, 2 = canUse, 3 = consumable)
   0, // Item 6 (0 = unavailable, 1 = bought, 2 = canUse, 3 = consumable)
   0, // Trinket (0 = unavailable, 1 = bought, 2 = canUse, 3 = consumable)
   0, // Team Order Player 1 (0 = not exists, 1 = dead, 2 = alive)
   0, // Team Order Player 2 (0 = not exists, 1 = dead, 2 = alive)
   0, // Team Order Player 3 (0 = not exists, 1 = dead, 2 = alive)
   0, // Team Order Player 4 (0 = not exists, 1 = dead, 2 = alive)
   0, // Team Order Player 5 (0 = not exists, 1 = dead, 2 = alive)
   0, // Team Chaos Player 1 (0 = not exists, 1 = dead, 2 = alive)
   0, // Team Chaos Player 2 (0 = not exists, 1 = dead, 2 = alive)
   0, // Team Chaos Player 3 (0 = not exists, 1 = dead, 2 = alive)
   0, // Team Chaos Player 4 (0 = not exists, 1 = dead, 2 = alive)
   0, // Team Chaos Player 5 (0 = not exists, 1 = dead, 2 = alive)
   0, // Spell D (0 = barrier, 1 = cleanse, 2 = ignite, 3 = exhaust, 4 = flash, 5 = ghost, 6 = heal, 7 = clarity, 8 = smite, 9 = mark, 10 = teleport)
   0, // Spell F (0 = barrier, 1 = cleanse, 2 = ignite, 3 = exhaust, 4 = flash, 5 = ghost, 6 = heal, 7 = clarity, 8 = smite, 9 = mark, 10 = teleport)
   0, // Order 1st Dragon
   0, // Order 2nd Dragon
   0, // Order 3rd Dragon
   0, // Order Soul Dragon
   0, // Chaos 1st Dragon
   0, // Chaos 2nd Dragon
   0, // Chaos 3rd Dragon
   0 // Chaos Soul Dragon
};

/* RGB Stuff */

int lol_get_state(int i) {
    if (i >= LOL_SIZE_STATE || i < 0) return -1;
    return lol_state[i];
}

void lol_set_state(uint8_t* command) {
    for (int i = 0; i < LOL_SIZE_STATE; i++) {
        lol_state[i] = command[i];
    }
}

int lol_colors_fixed[][3] = {
    CL_NEUTRAL,
    CL_PLAYER_DEAD
};
int lol_colors_skill[][3] = {
    CL_SKILL_EMPTY,
    CL_SKILL_LVL_1,
    CL_SKILL_LVL_2,
    CL_SKILL_LVL_3,
    CL_SKILL_LVL_4,
    CL_SKILL_LVL_5,
    CL_SKILL_LVL_6
};

int lol_colors_item[][3] = {
    CL_SKILL_EMPTY,
    CL_ITEM,
    CL_ITEM_USABLE,
    CL_ITEM_CONSUMABLE
};

int lol_colors_player[][3] = {
    CL_PLAYER_EMPTY,
    CL_PLAYER_DEAD,
    CL_PLAYER_ALIVE
};

int lol_colors_dragon[][3] = {
    {  0,    0,    0    },  // 0 None
    {  0,    0,    0    },  // 1 Elder
    {  255,  179,  25   },  // 2 Earth
    {  0,    85,   255  },  // 3 Water
    {  153,  255,  255  },  // 4 Air
    {  255,  85,   0    },  // 5 Fire
    {  85,   0,    255  },  // 6 Hextech
    {  153,  255,  51   },  // 7 Chemtech
};

int lol_colors_spell[][3] = {
    {  255,  255,  255  },  //  Unknown
    {  146,  109,  49   },  //  Barrier
    {  21,   110,  114  },  //  Cleanse
    {  118,  50,   21   },  //  Ignite
    {  0,    0,    0    },  //  Exhaust
    {  175,  156,  42   },  //  Flash
    {  19,   95,   129  },  //  Ghost
    {  128,  144,  100  },  //  Heal
    {  44,   95,   127  },  //  Clarity
    {  146,  93,   37   },  //  Smite
    {  111,  132,  179  },  //  Mark
    {  105,  31,   125  },  //  Teleport
    {  -1,  -1,    -1   }   //  Spellbook Placeholder
};

RGB lol_get_rgb(int color[3]) {
  if (!color) return lol_get_color(lol_colors_fixed[0]);
  return lol_get_color(color);
}

RGB lol_get_feature_color(int feature, int state) {
  switch (feature) {
    case 0: return lol_get_rgb(lol_colors_fixed[state]);
    case 1: return lol_get_rgb(lol_colors_skill[state]);
    case 2: return lol_get_rgb(lol_colors_item[state]);
    case 3: return lol_get_rgb(lol_colors_player[state]);
    case 4: return lol_get_rgb(lol_colors_spell[state]);
    case 5: return lol_get_rgb(lol_colors_dragon[state]);
  }
  return (RGB) { .r = -1, .g = -1, .b = -1 };
}

void lol_rgb_set_key_color(int key, int layer, int state) {
    RGB color = lol_get_feature_color(layer, state);
    if (color.r < 0) return;
    rgb_matrix_set_color(key, color.r, color.g, color.b);
}

void lol_rgb_set_layer_color(void) {
    int index;
    int feature;
    int state;
    for (int key = 0; key < DRIVER_LED_TOTAL; key++) {
        if (lol_state[0] == 0) {
            lol_rgb_set_key_color(key, 0, 0);
            continue;
        }

        index = indexOf(lol_layer_keymap, LOL_SIZE_KEY, key);
        feature = lol_layer_features[index];
        state = lol_get_state(index);

        if (feature == 3) {
            lol_rgb_set_key_color(key, 3, state);
            continue;
        }
        if (lol_state[1] == 1) {
            // TODO: Animate death
            lol_rgb_set_key_color(key, 0, 1);
            continue;
        }
        if (index < 0) {
            lol_rgb_set_key_color(key, 0, 0);
            continue;
        }
        lol_rgb_set_key_color(key, feature, state);
    }
}

/* Macros */

void lol_process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ST_LAUNCH_LOL_COMBO_3:
        case ST_LAUNCH_LOL_COMBO_2:
        case ST_LAUNCH_LOL:
        case ST_LOL: {
            if (record->event.pressed) {
                sky_set_layer(LOL_LAYER); // switch to LOL
            }
            break;
        }
    }
}
