/*
** EPITECH PROJECT, 2022
** MyHunter
** File description:
** my_csfml
*/

#ifndef MY_CSFML_H_
    #define MY_CSFML_H_

    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Window.h>



    ////////////////////////////////////////////////////////////
    /// \brief Macro for sfRenderWindow_close function
    ///
    /// Close a render window (but doesn't destroy the internal data)
    ///
    /// \param renderWindow Render window to close
    ///
    ////////////////////////////////////////////////////////////
    #define sRW_cl sfRenderWindow_close
    ////////////////////////////////////////////////////////////
    /// \brief Macro for sfTexture_createFromFile function
    ///
    /// Create a new texture from a file
    ///
    /// \param filename Path of the image file to load
    /// \param area     Area of the source image to load
    ///                 (NULL to load the entire image)
    ///
    /// \return A new sfTexture object, or NULL if it failed
    ///
    ////////////////////////////////////////////////////////////
    #define textureFromFile sfTexture_createFromFile
    ///A mouse button was pressed (data in event.mouseButton)
    #define sEMBP sfEvtMouseButtonPressed
    ///The left mouse button
    #define sML sfMouseLeft



    /* Display sprite */

    #define sS_cr sfSprite_create
    #define sS_sT sfSprite_setTexture

    ////////////////////////////////////////////////////////////
    /// \brief Create a sprite and give it a texture
    ///
    /// \param s Sprite object (sfSprite *)
    /// \param t Texture object (sfTexture *)
    ///
    ////////////////////////////////////////////////////////////
    #define dispSprite(s, t) (s = sS_cr(), sS_sT(s, t, sfTrue))



    /* Display text */

    #define sT_cr sfText_create
    #define sT_sS sfText_setString
    #define sT_sF sfText_setFont
    #define sT_sCS sfText_setCharacterSize

    #define dT1(t, st) (t = sT_cr(), sT_sS(t, st))
    #define dT2(t, f, s) (sT_sF(t, f), sT_sCS(t, s))
    ////////////////////////////////////////////////////////////
    /// \brief Create a text, give it a string, a font, and set its size
    ///
    /// \param t  Text object (sfText *)
    /// \param st String (char *)
    /// \param f  Font object (sfFont *)
    /// \param s  Size (unsigned int)
    ///
    ////////////////////////////////////////////////////////////
    #define dispText(t, st, f, s) (dT1(t, st), dT2(t, f, s))

#endif /* !MY_CSFML_H_ */
