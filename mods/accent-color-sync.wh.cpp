// ==WindhawkMod==
// @id                  accent-color-sync
// @name                Accent Color Sync
// @description         Restores Control Panel color opacity functionality
// @description:fr-FR   Retour de la fonctionnalité d'opacité des couleurs du Panneau de configuration
// @description:es-ES   Recuperar la funcionalidad de opacidad de colores del Panel de control
// @description:ja-JP   コントロールパネルの色の不透明度機能を復元する
// @version             1.51
// @author              CatmanFan / Mr._Lechkar
// @github              https://github.com/CatmanFan
// @include             explorer.exe
// @architecture        x86
// @architecture        x86-64
// @compilerOptions     -lcomdlg32 -lversion
// ==/WindhawkMod==

// ==WindhawkModReadme==
/*
Brings back the functionality of the Control Panel's "Color intensity" slider to Windows 10 1809 and above, using third-party DWM shader software (e.g. OpenGlass, Glass8). The mod synchronises the Aero colorization parameters used by the supported DWM customization software with the slider value.

## **⚠️ Requirements:**
**This mod requires that *one* of the following supported DWM shader applications is installed and running:**
* **[Legacy OpenGlass](https://github.com/ALTaleX531/OpenGlass/tree/legacy)**, supports Windows 10 1809 ― Windows 11 23H2;
  * It is generally recommended to compile the source code from the official repo, but a list of OpenGlass-legacy downloads is also available *[here](https://github.com/ALTaleX531/OpenGlass/releases)*.
* **[Glass8](https://archive.org/details/full-glass8-archive)**, supports Windows 10 RTM to 1909 builds.
  * Please note that the shader used by this software is not accurate to the original.

### **Additional tips:**
* If you are updating this mod from version 1.3, it is recommended to also enable the *Sync with DWM* option in the mod settings, although this can have some minor bugs (see below).
* If you are updating this mod from version 1.0, it is required to disable or uninstall any unsupported DWM shader software (e.g. regular OpenGlass or DWMBlurGlass).
* You may need to try changing the accent color manually if changes do not automatically take effect.
* If one of the OpenGlass options in the *'DWM customization software'* section of the mod settings (i.e. the options labelled "OpenGlass" or "OpenGlass (old registry name)") is not working, try setting it to the other one. This is because while official builds of OpenGlass now use the registry value name template "{xxx}Override" instead of the older "og_{xxx}", this is not the case for older separately-compiled builds.

----

### Known bugs:
* ***Sync with DWM* option enabled:**
  * When changing the color intensity in the Control Panel without changing the color itself, the theme preview icon used for the color does not change unless after the theme preview is regenerated by changing the color RGB values or the desktop background.
* Actually closing the Personalization window does not produce the same behaviour as clicking "Cancel" (i.e. the RGB color is changed but the OpenGlass opacity stays the same).
* When using [Explorer7](https://github.com/Erizur/explorer7-releases/), the Start menu may not immediately change in opacity and requires a restart of explorer.exe. This may be fixed with schm1dt's glass POC mod downloadable [here](https://winclassic.net/post/24274).

### Special credits:
* [OjasK](https://github.com/ojask) for his DirectUI reverse-engineering work, part of which was referenced in the making of this mod.
* [ALTaleX](https://github.com/ALTaleX531) for the incredible work on OpenGlass, and on porting the Windows 7 DWM colorization functionality to open-source code with [this formula](https://github.com/ALTaleX531/dwm_colorization_calculator); as well as [kfh83](https://github.com/kfh83) on porting the Windows 7-esque shader to OpenGlass-legacy.

*/
// ==/WindhawkModReadme==

// ==WindhawkModSettings==
/*
- fixedOpacity:
  - enable: FALSE
    $name: Enabled
    $name:fr-FR: Activer l'option
    $name:es-ES: Habilitada
    $name:ja-JP: 有効化
  - value: 25
    $name: Value (0-100)
    $name:fr-FR: Valeur (0-100)
    $name:es-ES: Valor (0-100)
    $name:ja-JP: 値（0～100）
  $name: Fixed opacity
  $name:fr-FR: Opacité fixe
  $name:es-ES: Opacidad fijada
  $name:ja-JP: 一定の不透明度
  $description: Permanently sets the OpenGlass opacity at a fixed value. This can be useful if the color is set to automatic based on desktop background.
  $description:fr-FR: Définir l'opacité d'OpenGlass de façon permanente sur une valeur fixe. Cela peut être utile lorsque la couleur d'accentuation est automatiquement extraite d'un arrière-plan.
  $description:es-ES: Establece de forma permanente la opacidad de OpenGlass en un valor fijo. Puede ser útil para cualquier color de énfasis del fondo de escritorio.
  $description:ja-JP: オーペングラスの不透明度を一定の値に設定します。アクセントカラーが背景から自動的に設定されると有益かもしれません。
- syncDWM: TRUE
  $name: Sync with DWM
  $name:fr-FR: Synchroniser avec DWM
  $name:es-ES: Sincronizar con DWM
  $name:ja-JP: DWMと同期する
  $description: Writes the opacity value to DWM's color and afterglow variables. This makes it so that the opacity is also written to the theme alongside the color's RGB. Otherwise, Windows automatically sets it to remain stationary at 0xc4 (196 of 255).
  $description:fr-FR: Sauvegarder la valeur d'opacité aux options de DWM. Cela permet de définir également l'opacité dans le thème simultanément avec les valeurs du RVB. Sinon, Windows le définit en permanence à 0xc4 (196 sur 255).
  $description:es-ES: Guarda el valor de opacidad de OpenGlass en DWM. Esto lo permite guardar la opacidad del tema que Windows normalmente siempre establece en 0xc4, o 196 de 255, simultáneamente con los valores RGB.
  $description:ja-JP: 不透明度の値をDWM設定に保存します。
- glassSoftware: og2
  $options:
  - og2: OpenGlass
  - og1: OpenGlass (old registry name)
  - glass8: Glass8
  $options:fr-FR:
  - og2: OpenGlass
  - og1: OpenGlass (anciennes valeurs de registre)
  - glass8: Glass8
  $options:es-ES:
  - og2: OpenGlass
  - og1: OpenGlass (nombres antiguos de valores de registro)
  - glass8: Glass8
  $options:ja-JP:
  - og2: OpenGlass
  - og1: OpenGlass（レジストリ値の古い名前）
  - glass8: Glass8
  $name: DWM customization software
  $name:fr-FR: Logiciel de modification du gestionnaire des fenêtres (DWM)
  $name:es-ES: Software de modificación de interfaz gráfica DWM
  $name:ja-JP: DWMカスタマイズソフトウェア
  $description: The application currently being used to implement the Aero shader.
  $description:fr-FR: L'application actuellement utilisée pour implémenter le shader Aero classique.
  $description:es-ES: La aplicación que se utiliza actualmente para implementar la funcionalidad de Aero.
  $description:ja-JP: Aeroシェーダー効果を反映するために現在使用されているアプリケーション
*/
// ==/WindhawkModSettings==

#include <winnt.h>
#if _WIN64
#define THISCALL __cdecl
#define STHISCALL L"__cdecl"
#define STDCALL __cdecl
#define SSTDCALL L"__cdecl"
#define STRTOID_NAME L"StrToID"
#else
#define THISCALL __thiscall
#define STHISCALL L"__thiscall"
#define STDCALL __stdcall
#define SSTDCALL L"__stdcall"
#define STRTOID_NAME L"_StrToID@4"
#endif

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <cmath>
#include <windhawk_api.h>
#include <windhawk_utils.h>
#include <winver.h>

const std::wstring dwmKey = L"SOFTWARE\\Microsoft\\Windows\\DWM";
const std::wstring opacityValue = L"og_Opacity";

enum class GlassSoftware { OpenGlass2, OpenGlass1, Glass8 };
enum class WinVersion { None, Unsupported, Win10, Win11 };
WinVersion winVer;

struct {
	GlassSoftware glassApp;
    int opacity;
    int fixedOpacity;
    bool fixedOpacitySet;
    bool boolTransparency;
    bool boolSyncDWM;
} settings;

std::wstring balanceColor;
std::wstring balanceAfterglow;
std::wstring balanceBlur;

#pragma region ----- Registry functions -----
/**
 * Reads a string value from a registry key within HKCU.
 *
 * @param sk The path to the key, not including "HKCU\".
 * @param v The name of the value.
 * @return The string value if it is found, otherwise `NULL`.
 */
std::wstring read_SZ(std::wstring sk, std::wstring v, std::wstring defaultValue)
{
    const LPCTSTR subkey = sk.c_str();
    const LPCTSTR value = v.c_str();
    WCHAR szBuffer[512];
    DWORD size(sizeof(szBuffer));

    HKEY hKey;
    LONG openRes = RegOpenKeyEx(HKEY_CURRENT_USER, subkey, 0, KEY_READ, &hKey);
    if (openRes == ERROR_SUCCESS) {
        LONG setRes = RegQueryValueEx(hKey, value, 0, NULL, (LPBYTE)&szBuffer, &size);
        RegCloseKey(hKey);

        if (setRes == ERROR_SUCCESS) {
            defaultValue = szBuffer;
        }
    }

    return defaultValue;
}

/**
 * Reads a DWORD value from a registry key within HKCU.
 *
 * @param sk The path to the key, not including "HKCU\".
 * @param v The name of the value.
 * @return The DWORD value if it is found, otherwise `NULL`.
 */
DWORD read_DWORD(std::wstring sk, std::wstring v)
{
    const LPCTSTR subkey = sk.c_str();
    const LPCTSTR value = v.c_str();
    DWORD data(0);
    DWORD size(sizeof(DWORD));

    HKEY hKey;
    LONG openRes = RegOpenKeyEx(HKEY_CURRENT_USER, subkey, 0, KEY_READ, &hKey);
    if (openRes != ERROR_SUCCESS) {
        return NULL;
    }

    LONG setRes = RegQueryValueEx(hKey, value, 0, NULL, reinterpret_cast<LPBYTE>(&data), &size);
    RegCloseKey(hKey);

    if (setRes == ERROR_SUCCESS) {
        return data;
    } else {
        return NULL;
    }
}

/**
 * Checks for the existence of a DWORD value within an HKCU registry key.
 *
 * @param sk The path to the key, not including "HKCU\".
 * @param v The name of the value.
 * @return `TRUE` if found, otherwise `FALSE`.
 */
BOOL exists_DWORD(std::wstring sk, std::wstring v)
{
    const LPCTSTR subkey = sk.c_str();
    const LPCTSTR value = v.c_str();
    DWORD data(0);
    DWORD size(sizeof(DWORD));

    HKEY hKey;
    LONG openRes = RegOpenKeyEx(HKEY_CURRENT_USER, subkey, 0, KEY_ALL_ACCESS, &hKey);
    LONG setRes = RegQueryValueEx(hKey, value, 0, NULL, reinterpret_cast<LPBYTE>(&data), &size);
    RegCloseKey(hKey);

    if (openRes != ERROR_SUCCESS || setRes != ERROR_SUCCESS) {
        return FALSE;
    } else {
        return TRUE;
    }
}

/**
 * Checks for the existence of a registry key within HKCU.
 *
 * @param sk The path to the key, not including "HKCU\".
 * @return `TRUE` if found, otherwise `FALSE`.
 */
BOOL exists_Key(std::wstring sk)
{
    const LPCTSTR subkey = sk.c_str();

    HKEY hKey;
    LONG openRes = RegOpenKeyEx(HKEY_CURRENT_USER, subkey, 0, KEY_ALL_ACCESS, &hKey);
    if (openRes != ERROR_SUCCESS) {
        return FALSE;
    } else {
        return TRUE;
    }
}

/**
 * Writes a DWORD value to a registry key within HKCU.
 *
 * @param sk The path to the key, not including "HKCU\".
 * @param v The name of the value.
 * @param data The DWORD value to write.
 * @return `TRUE` if the operation succeeded, otherwise `FALSE`.
 */
BOOL set_DWORD(std::wstring sk, std::wstring v, unsigned long data, bool del = FALSE)
{
    const LPCTSTR subkey = sk.c_str();
    const LPCTSTR value = v.c_str();

    HKEY hKey;
    LONG openRes = RegOpenKeyEx(HKEY_CURRENT_USER, subkey, 0, KEY_ALL_ACCESS, &hKey);
    if (openRes != ERROR_SUCCESS) {
        Wh_Log(L"Failed to open registry key");
        return FALSE;
    }

    LONG setRes = del ? RegDeleteValue(hKey, value) : RegSetValueEx(hKey, value, 0, REG_DWORD, (const BYTE*)&data, sizeof(data));
    RegCloseKey(hKey);

    if (setRes == ERROR_SUCCESS) {
        return TRUE;
    } else {
        Wh_Log(L"Failed writing to registry");
        return FALSE;
    }
}
#pragma endregion

#pragma region ----- DWM colorization calculator -----
/* ----------------------------------------------------------------------------
// Original code is by ALTaleX !! (converted from Python)
// https://github.com/ALTaleX531/dwm_colorization_calculator/blob/main/main.py
// ----------------------------------------------------------------------------
//
// **************************************
// IN ORDER:
// 1. HSB and ARGB
// 2. Colorization color, which generates ARGB from intensity and HSB and is convertable
// 3. DWM colorization parameters (the good stuff)
// **************************************
//
// ----------------------------------------------------------------------------
// ALL DOCUMENTATION FOLLOWING THIS COMMENT HAS BEEN COPIED FROM THEIR CODE FOR REFERENCE.
// ----------------------------------------------------------------------------
*/

class dwm_colorization_parameters;

class colorization_color;

class hsb {
public:
    float hue; // 0-360
    float saturation; // 0-1
    float brightness; // 0-1

    hsb(float hue, float saturation, float brightness) : hue(hue), saturation(saturation), brightness(brightness) {
    }

    void log() { Wh_Log(L"[H: %d, S: %d, B: %d]", hue, saturation, brightness); }
};

class argb { public:
    int value;

    argb(int value) : value(value) {}

    int get_a() const { return (this->value & 0xFF000000) >> 24; }
    int get_r() const { return (this->value & 0x00FF0000) >> 16; }
    int get_g() const { return (this->value & 0x0000FF00) >> 8; }
    int get_b() const { return (this->value & 0x000000FF); }

    static argb from_argb_channel(float a, float r, float g, float b) {
        return argb(
            ((static_cast<int>(round(a * 255.0 + 0.5)) & 0xFF) << 24) |
            ((static_cast<int>(round(r * 255.0 + 0.5)) & 0xFF) << 16) |
            ((static_cast<int>(round(g * 255.0 + 0.5)) & 0xFF) << 8) |
            ((static_cast<int>(round(b * 255.0 + 0.5)) & 0xFF))
        );
    }
};

class colorization_color : public argb { public:
    colorization_color(int value) : argb(value) {}

    // themecpl.dll!CColorizationColor::CColorizationColor
    static colorization_color from_hsb(const hsb& color, float intensity) {
        float r, g, b;

        if (color.saturation == 0.0)
            r = g = b = color.brightness;
        else
		{
            float value = color.hue / 60.0;
            float difference = value - round(value);

            if (0.0 < color.hue && color.hue <= 60.0)
			{
                g = (1.0 - (1.0 - difference) * color.saturation) * color.brightness;
                b = (1.0 - color.saturation) * color.brightness;
                r = color.brightness;
			}
            if (60.0 < color.hue && color.hue <= 120.0)
			{
                r = (1.0 - difference * color.saturation) * color.brightness;
                g = color.brightness;
                b = (1.0 - color.saturation) * color.brightness;
			}
            if (120.0 < color.hue && color.hue <= 180.0)
			{
                r = (1.0 - color.saturation) * color.brightness;
                g = color.brightness;
                b = (1.0 - (1.0 - difference) * color.saturation) * color.brightness;
			}
            if (180.0 < color.hue && color.hue <= 240.0)
			{
                r = (1.0 - color.saturation) * color.brightness;
                g = (1.0 - difference * color.saturation) * color.brightness;
                b = color.brightness;
			}
            if (240.0 < color.hue && color.hue <= 300.0)
			{
                r = (1.0 - (1.0 - difference) * color.saturation) * color.brightness;
                g = (1.0 - color.saturation) * color.brightness;
                b = color.brightness;
			}
            if (300.0 < color.hue && color.hue <= 360.0)
			{
                g = (1.0 - color.saturation) * color.brightness;
                b = (1.0 - difference * color.saturation) * color.brightness;
                r = color.brightness;
			}
        }

        return colorization_color
		(
            argb::from_argb_channel(intensity, r, g, b).value
        );
    }

    // themecpl.dll!CColorCplPage::UpdateSlidersToReflectColor
    // The range for the slider is about [10%, 85%], normally you can't make it bigger or smaller
    float get_intensity() const { return this->get_a() / 255.0f; }

    // themecpl.dll!CColorCplPage::UpdateSlidersToReflectColor
    hsb get_hsb_color() const {
        float r = this->get_r() / 255.0f;
        float g = this->get_g() / 255.0f;
        float b = this->get_b() / 255.0f;

        float brightness = std::max({r, g, b});
        float darkness = std::min({r, g, b});
        float range_value = brightness - darkness;
        float saturation, value;

        if (brightness == 0.0 || range_value == 0.0) {
            saturation = 0.0;
            value = 0.0;
        } else {
            saturation = range_value / brightness;
            if (r == brightness) {
                value = (g - b) / range_value;
            } else if (g == brightness) {
                value = (b - r) / range_value + 2.0;
            } else {
                value = (r - g) / range_value + 4.0;
            }
        }

        float hue = value * 60.0;
        if (hue < 0.0) hue += 360.0;

        return hsb(hue, saturation, brightness);
    }
};

class dwm_colorization_parameters {
public:
    argb color;
    argb afterglow;
    int color_balance;
    int afterglow_balance;
    int blur_balance;
    int glass_reflection_intensity;
    bool opaque_blend;

    dwm_colorization_parameters(
        argb color 						= argb(0x6b74b8fc),	//.0 a is actually ignored in the shader
        argb afterglow					= argb(0x6b74b8fc),	//.1 a is actually ignored in the shader
        int color_balance				= 8,				//.2 0..100
        int afterglow_balance			= 43,				//.3 0..100
        int blur_balance				= 49,				//.4 0..100
        int glass_reflection_intensity	= 50,				//.5 0..100
        bool opaque_blend				= false				//.6
    ) : color(color), afterglow(afterglow), color_balance(color_balance),
        afterglow_balance(afterglow_balance), blur_balance(blur_balance),
        glass_reflection_intensity(glass_reflection_intensity), opaque_blend(opaque_blend) {}

    // themecpl.dll!ConvertColorizationParametersToARGB
    colorization_color convert_colorization_parameters_to_argb() {
        int balance = 0;

        if (opaque_blend) {
            balance = color_balance;
        } else if (blur_balance < 50) {
            if (blur_balance <= 23) {
                balance = color_balance + 25;
            } else {
                balance = 95 - afterglow_balance;
            }
        } else {
            balance = 100 - blur_balance;
        }

        return (color.value & 0xFFFFFF) | ((static_cast<int>(round(((balance - 10.0f)) * 0.75 / 100.0 + 0.1) * 255.0 + 0.5) & 0xFF) << 24);
    }

    // themecpl.dll!CColorCplPage::Setup
    // used by theme control panel
    colorization_color to_colorization_color() {
        int argb_color = 0;

        if ((color.value & 0xFF000000) == 0xFF000000)
            argb_color = convert_colorization_parameters_to_argb().value;
        else
            argb_color = color.value;

        return colorization_color(argb_color);
    }

    // udwm.dll!DwmpCalculateColorizationColor
    // used by WM_DWMCOLORIZATIONCOLORCHANGED and DwmGetColorizationColor
    //
    // https://stackoverflow.com/questions/3560890/vista-7-how-to-get-glass-color
    // It's almost unusable, I keep it simply because its implementation exists inside udwm.dll from Windows 7.
    colorization_color calculate_dwm_color() {
        float afterglow_balance = this->afterglow_balance / 100.0f;
        float color_balance = this->color_balance / 100.0f;

        float color_r = color.get_r() / 255.0f;
        float color_g = color.get_g() / 255.0f;
        float color_b = color.get_b() / 255.0f;

        float afterglow_r = afterglow.get_r() / 255.0f;
        float afterglow_g = afterglow.get_g() / 255.0f;
        float afterglow_b = afterglow.get_b() / 255.0f;

        float result_a = std::max(0.0, (1.0 - afterglow_balance) - (blur_balance / 100.0f));
        float brightness = (color_g * 0.7152 + color_r * 0.2126 + color_b * 0.0722) * afterglow_balance * color_balance;

        float result_r = afterglow_r * brightness + color_r * color_balance;
        float result_g = afterglow_g * brightness + color_g * color_balance;
        float result_b = afterglow_b * brightness + color_b * color_balance;

        return colorization_color(
            argb::from_argb_channel(
                result_a,
                result_r,
                result_g,
                result_b
            ).value
        );
    }
};

/* ----------------------------------------------------------------------------
// CONVERSION OF ORIGINAL CODE AND COPIED DOCUMENTATION END HERE.
// ----------------------------------------------------------------------------
*/
#pragma endregion

#pragma region ----- DWM colorization calculation: Functions -----
colorization_color old = NULL;
colorization_color current = NULL;
hsb HSB = current.get_hsb_color();
dwm_colorization_parameters dwmSettings;
DWORD modified;

int intensitySliderMin = 10;
int intensitySliderMax = 85;
int valueTo100(int x) { return x - intensitySliderMin / (intensitySliderMax - intensitySliderMin) * 100; }
int valueFrom100(int x) { return (x / 100) * (intensitySliderMax - intensitySliderMin) + intensitySliderMin; }
#pragma endregion

DWORD readColor()
{
    const std::wstring value = L"ColorizationColor";

    if (!exists_DWORD(dwmKey, value))
        return 0xFF000000;
    else
        return read_DWORD(dwmKey, value);
}

void loadColorValues(DWORD input)
{
    current = colorization_color(input);
    dwmSettings = dwm_colorization_parameters(current.value, current.value, 0, 0, 0, 50, !settings.boolTransparency);
    HSB = current.get_hsb_color();
}

/**
 * Writes color, afterglow and blur values to OpenGlass/Glass8 registry settings.
 * @param c Color
 * @param a Afterglow
 * @param a Blur
 */
void writeColorizationBalance(int c, int a, int b)
{
    if (settings.glassApp == GlassSoftware::Glass8) {
        set_DWORD(dwmKey, balanceColor, c);
        set_DWORD(dwmKey, balanceBlur, b);
    } else {
        set_DWORD(dwmKey, balanceColor, c);
        set_DWORD(dwmKey, balanceAfterglow, a);
        set_DWORD(dwmKey, balanceBlur, b);
    }
}

// ----------------------------------------------------------------------------
// Taken from "to_dwm_colorization_parameters" function (again, by ALTaleX):
// https://github.com/ALTaleX531/dwm_colorization_calculator/blob/main/main.py#L110
// ----------------------------------------------------------------------------
void calculateIntensity(DWORD self, bool opaque = FALSE)
{
    int balance = round((static_cast<float>((self >> 24) & 0xFF) / 255.0 - 0.1) / 0.75 * 100.0 + 10.0);
    dwmSettings = dwm_colorization_parameters(self, self);
    dwmSettings.glass_reflection_intensity = 50;
    dwmSettings.opaque_blend = opaque;

    if (dwmSettings.opaque_blend) {
        dwmSettings.afterglow_balance = 10;
        dwmSettings.color_balance = balance - dwmSettings.afterglow_balance;
        dwmSettings.blur_balance = 100 - balance;
        return;
    }

    if (balance < 50) {
        dwmSettings.color_balance = 5;
        dwmSettings.blur_balance = 100 - balance;
        dwmSettings.afterglow_balance = (100 - dwmSettings.color_balance) - dwmSettings.blur_balance;
        return;
    }

    if (balance >= 95) {
        dwmSettings.afterglow_balance = 0;
        dwmSettings.color_balance = balance - 25;
        dwmSettings.blur_balance = 100 - dwmSettings.color_balance;
        return;
    }

    dwmSettings.afterglow_balance = 95 - balance;
    dwmSettings.blur_balance = 50 - ((balance - 50) >> 1);
    dwmSettings.color_balance = 100 - dwmSettings.afterglow_balance - dwmSettings.blur_balance;
}

int opacity = -1;
/**
 * Writes the OpenGlass opacity value to DWM's color and afterglow values in registry.
 */
void bruteforceOpacity()
{
    if (!settings.boolSyncDWM)
        return;

    argb dwm(readColor());
    argb og(dwmSettings.to_colorization_color().value);
    if (dwm.value == 0x52fadc0e) dwm.value = 0x54fadc0e; // Sun
    if (dwm.value == og.value) return;
    int opacity = og.get_a();

    // Hotfixes to match with Windows 7 accent colors
    if (opacity == 0x69 || opacity == 0x6a)
        opacity = 0x6b;
    if (opacity == 0xa6 || opacity == 0xa7)
        opacity = 0xa8;
    if (opacity == 0x67)
        opacity = 0x66;
    if (opacity == 0x6e || opacity == 0x6f)
        opacity = 0x70;
    if (dwm.value == 0x54fadc0e)
        opacity = 0x54;

    DWORD New = (dwm.value & 0x00ffffff) | (opacity << 24);
    set_DWORD(dwmKey, L"ColorizationColor", New);
    set_DWORD(dwmKey, L"ColorizationAfterglow", New);

    dwmSettings.color = dwmSettings.afterglow = New;
}

/**
 * Calculates the color, afterglow and blur intensity values from an integer out of 100, then writes them to the registry for use with OpenGlass.
 * @param bruteforce Determines whether to also simultaneously bruteforce the opacity value to DWM.
 */
void setColorizationBalance(bool bruteforce = FALSE)
{
    // *********************************************
    // Set "og_Opacity" value.

    if (settings.opacity < 0 || settings.opacity > 100)
        settings.opacity = 42; // 40.7853080838;
    if (opacity < 0 || opacity > 100)
        opacity = settings.opacity;
    set_DWORD(dwmKey, opacityValue, opacity);
    
    // Return if the function has already been run once under a fixed opacity.
    // This is to prevent useless DWM refreshing afterward.
    
    if (settings.fixedOpacitySet) return;
    bool isFixed = settings.fixedOpacity >= 0 && settings.fixedOpacity <= 100;
    if (isFixed) settings.fixedOpacitySet = TRUE;
    // *********************************************

    float alpha = (isFixed ? settings.fixedOpacity : opacity) / 100.0f;

    // *********************************************
    // Min: 26, max: 217
    // NOTE: Changing the ColorizationColor and Afterglow also affects the intensity slider
    // *********************************************
    loadColorValues((current.value & 0x00FFFFFF) | ((int(alpha * 255.0 + 0.5) & 0xFF) << 24));
    calculateIntensity(current.value, !settings.boolTransparency);

    // *********************************************
    // Actually do the registry editing
    // *********************************************
    writeColorizationBalance(dwmSettings.color_balance, dwmSettings.afterglow_balance, dwmSettings.blur_balance);
    
    // Other registry values
    set_DWORD(dwmKey, L"GlassOpacity", 0); // settings.boolTransparency ? 0 : 100);
    set_DWORD(dwmKey, L"GlassType", 1);    // settings.boolTransparency ? 1 : 0);

    if (bruteforce)
		bruteforceOpacity();

    PostMessage(FindWindow(TEXT("dwm"), nullptr), WM_DWMCOLORIZATIONCOLORCHANGED, 0, 0);
}

#pragma region ----- DirectUI hooks -----
typedef ATOM WINAPI (*StrToId_T)(unsigned const short*);
StrToId_T StrToID;

// Pointers to DUI elements
intptr_t intensitySlider = 0;
intptr_t okButton = 0;
intptr_t cancelButton = 0;

typedef unsigned short (*THISCALL Element_GetID_T)(class Element*, void*);
Element_GetID_T Element_GetID;

void (*THISCALL Element_OnPropertyChanged)(class Element*, class PropertyInfo const*, int, class Value*, class Value*);
void THISCALL Element_OnPropertyChanged_hook(class Element* This, class PropertyInfo const* prop, int integer, class Value* valueA, class Value* valueB)
{
    Element_OnPropertyChanged(This, prop, integer, valueA, valueB);
    auto ptr = reinterpret_cast<intptr_t>(This);
    if (ptr <= 0) return;

    ATOM id = Element_GetID(This, &This);

    if (intensitySlider != id && id == StrToID((unsigned const short*)L"IntensitySlider"))
        intensitySlider = ptr;

    // *********************************************
    // The bruteforcing here has to be done so that the default alpha color value is overwritten
    // *********************************************
    else if (okButton != id && id == StrToID((unsigned const short*)L"OkButton")) {
        okButton = ptr;
        bruteforceOpacity();
    }
    else if (cancelButton != id && id == StrToID((unsigned const short*)L"CancelButton")) {
        cancelButton = ptr;
        bruteforceOpacity();
    }
}

long (*THISCALL CCTrackBar_SetThumbPosition)(class CCTrackBar*, int);
long THISCALL CCTrackBar_SetThumbPosition_hook(class CCTrackBar* This, int value)
{
    auto ptr = reinterpret_cast<intptr_t>(This);

    // Track bar value
    if (intensitySlider > 0 && intensitySlider == ptr) {
        opacity = value;
        set_DWORD(dwmKey, opacityValue, opacity);
        setColorizationBalance();
    }

    return CCTrackBar_SetThumbPosition(This, value);
}

/**
 * -------------------------
 * Function for permanent hooking of opacity to DWM when OK/Cancel is clicked
 * -------------------------
 */
typedef void (*THISCALL CCPushButton_OnSelectedPropertyChanged_T)(class CCPushButton*, void*);
CCPushButton_OnSelectedPropertyChanged_T CCPushButton_OnSelectedPropertyChanged;
void THISCALL CCPushButton_OnSelectedPropertyChanged_hook(class CCPushButton* This, void* that)
{
    auto ptr = reinterpret_cast<intptr_t>(This);

    // OK button
    if (ptr > 0 && ptr == okButton) {
        settings.opacity = opacity;
        bruteforceOpacity();
    }

    // Cancel button
    else if (ptr > 0 && ptr == cancelButton) {
        opacity = settings.opacity;
		loadColorValues(old.value);
        setColorizationBalance(TRUE);
		
        if (intensitySlider > 0)
            CCTrackBar_SetThumbPosition(reinterpret_cast<class CCTrackBar*>(intensitySlider), opacity);
    }

    CCPushButton_OnSelectedPropertyChanged(This, that);
}
#pragma endregion

#pragma region ##ThemeUI hooks##

enum DWMPGLASSATTRIBUTE : INT {
    DWMPGA_TRANSPARENCY_ALLOWED = 0x0,
    DWMPGA_TRANSPARENCY_DISALLOWED = 0x1,
    DWMPGA_NO_GLASS = 0x2,
    DWMPGA_LAST = 0x3,
};

/**
 * -------------------------
 * Function for setting DWM colorization when the theme is changed from the Control Panel
 * -------------------------
 */
long (*STDCALL SetDwmColorizationColor)(unsigned long, enum DWMPGLASSATTRIBUTE, int);
long STDCALL SetDwmColorizationColor_hook(unsigned long color, enum DWMPGLASSATTRIBUTE attribute, int integer)
{
    settings.opacity = opacity = round(argb(color).get_a() / 255.0 * 100.0);
    old = colorization_color(color);
	loadColorValues(old.value);
    setColorizationBalance();

    return SetDwmColorizationColor(color, attribute, integer);
}
#pragma endregion

WindhawkUtils::SYMBOL_HOOK dui70dll_hooks[] = {
    {
        {STRTOID_NAME},
        (void**)&StrToID,
    },

    {
        {L"public: unsigned short " STHISCALL " DirectUI::Element::GetID(void)"},
        (void**)&Element_GetID
    },

    {
        {L"public: virtual void " STHISCALL " DirectUI::Element::OnPropertyChanged(struct DirectUI::PropertyInfo const *,int,class DirectUI::Value *,class DirectUI::Value *)"},
        (void**)&Element_OnPropertyChanged,
        (void*)Element_OnPropertyChanged_hook
    },

    {
        {L"public: long " STHISCALL " DirectUI::CCTrackBar::SetThumbPosition(int)"},
        (void**)&CCTrackBar_SetThumbPosition,
        (void*)CCTrackBar_SetThumbPosition_hook
    },

    {
        {L"public: virtual void " STHISCALL " DirectUI::CCPushButton::OnSelectedPropertyChanged(void)"},
        (void**)&CCPushButton_OnSelectedPropertyChanged,
        (void*)&CCPushButton_OnSelectedPropertyChanged_hook
    }
};

WindhawkUtils::SYMBOL_HOOK themeuidll_hooks[] = {
    {
        {L"long " SSTDCALL " SetDwmColorizationColor(unsigned long,enum DWMPGLASSATTRIBUTE,int)"},
        (void**)&SetDwmColorizationColor,
        (void*)SetDwmColorizationColor_hook
    }
};

typedef NTSTATUS(NTAPI* RtlGetVersion_t)(PRTL_OSVERSIONINFOW);
RtlGetVersion_t RtlGetVersion;
WinVersion getWinVer()
{
    HMODULE hNtDll = LoadLibraryW(L"ntdll.dll");
    if (!hNtDll)
        return WinVersion::None;

    RtlGetVersion = (RtlGetVersion_t)GetProcAddress(hNtDll, "RtlGetVersion");
    if (!RtlGetVersion)
        return WinVersion::None;

    RTL_OSVERSIONINFOW osv = { sizeof(RTL_OSVERSIONINFOW) };
    if (RtlGetVersion(&osv) == 0x00) {
        WORD major = osv.dwMajorVersion;
        WORD minor = osv.dwMinorVersion;
        WORD build = osv.dwBuildNumber;
        Wh_Log(L"Current OS version: %u.%u (build %u)", major, minor, build);

        switch (major) {
			case 10:
				if (build < 22000)
					return WinVersion::Win10;
				else
					return WinVersion::Win11;
				break;

			default:
				return WinVersion::Unsupported;
        }
    }

    return WinVersion::None;
}

BOOL isInstalled(bool strict = FALSE)
{
    return settings.glassApp == GlassSoftware::Glass8
           ? (strict ? exists_DWORD(dwmKey, balanceColor) && exists_DWORD(dwmKey, balanceBlur)
                     : exists_DWORD(dwmKey, balanceColor) || exists_DWORD(dwmKey, balanceBlur))
           : (strict ? exists_DWORD(dwmKey, balanceColor) && exists_DWORD(dwmKey, balanceAfterglow) && exists_DWORD(dwmKey, balanceBlur)
                     : exists_DWORD(dwmKey, balanceColor) || exists_DWORD(dwmKey, balanceAfterglow) || exists_DWORD(dwmKey, balanceBlur));
}

void setValueNames()
{
    if (settings.glassApp == GlassSoftware::Glass8)
    {
        balanceColor = L"ColorizationColorBalance";
        balanceBlur = L"ColorizationBlurBalance";
        return;
    }

    DWORD value;

    std::wstring old1 = settings.glassApp == GlassSoftware::OpenGlass2 ? L"og_ColorizationColorBalance"     : L"ColorizationColorBalanceOverride";
    std::wstring old2 = settings.glassApp == GlassSoftware::OpenGlass2 ? L"og_ColorizationAfterglowBalance" : L"ColorizationAfterglowBalanceOverride";
    std::wstring old3 = settings.glassApp == GlassSoftware::OpenGlass2 ? L"og_ColorizationBlurBalance"      : L"ColorizationBlurBalanceOverride";
    std::wstring new1 = settings.glassApp == GlassSoftware::OpenGlass1 ? L"og_ColorizationColorBalance"     : L"ColorizationColorBalanceOverride";
    std::wstring new2 = settings.glassApp == GlassSoftware::OpenGlass1 ? L"og_ColorizationAfterglowBalance" : L"ColorizationAfterglowBalanceOverride";
    std::wstring new3 = settings.glassApp == GlassSoftware::OpenGlass1 ? L"og_ColorizationBlurBalance"      : L"ColorizationBlurBalanceOverride";

    balanceColor = new1;
    balanceAfterglow = new2;
    balanceBlur = new3;

    if (exists_DWORD(dwmKey, old1)) {
        value = read_DWORD(dwmKey, old1);
        set_DWORD(dwmKey, new1, value);
        set_DWORD(dwmKey, old1, value, TRUE);
    }

    if (exists_DWORD(dwmKey, old2)) {
        value = read_DWORD(dwmKey, old2);
        set_DWORD(dwmKey, new2, value);
        set_DWORD(dwmKey, old2, value, TRUE);
    }

    if (exists_DWORD(dwmKey, old3)) {
        value = read_DWORD(dwmKey, old3);
        set_DWORD(dwmKey, new3, value);
        set_DWORD(dwmKey, old3, value, TRUE);
    }
}

BOOL LoadSettings()
{
	LPCWSTR glassAppName = Wh_GetStringSetting(L"glassSoftware");
    if (lstrcmpW(glassAppName, L"glass8") == 0)     settings.glassApp = GlassSoftware::Glass8;
    else if (lstrcmpW(glassAppName, L"og1") == 0)   settings.glassApp = GlassSoftware::OpenGlass1;
    else                                            settings.glassApp = GlassSoftware::OpenGlass2;
    Wh_FreeStringSetting(glassAppName);

    settings.fixedOpacity = -1;
    if (Wh_GetIntSetting(L"fixedOpacity.enable") == 1) {
        int opac = Wh_GetIntSetting(L"fixedOpacity.value");
        settings.fixedOpacity = opac < 0 || opac > 100 ? -1 : std::max(intensitySliderMin, std::min(opac, intensitySliderMax));
    }
    settings.fixedOpacitySet = FALSE;

    settings.boolTransparency = TRUE;
    settings.boolSyncDWM = Wh_GetIntSetting(L"syncDWM");

    bool regSetup = FALSE;
    setValueNames();

    // *********************************************
    // Check for OpenGlass/Glass8 installation
    // *********************************************
    if (!isInstalled()) {
        if (settings.glassApp == GlassSoftware::Glass8)
			Wh_Log(L"Glass8 was not detected, stopping now");
        else
			Wh_Log(L"OpenGlass Legacy was not detected, stopping now");
        return FALSE;
    } else {
        regSetup = !isInstalled(TRUE);
    }

    // *********************************************
    // Check/load from opacity DWORD in registry
    // *********************************************
    if (!exists_DWORD(dwmKey, opacityValue))
        regSetup = TRUE;
    else
        settings.opacity = read_DWORD(dwmKey, opacityValue);

    // *********************************************
    // Setup if those checks were not fully met
    // *********************************************
    if (regSetup) {
        Wh_Log(L"Setting up registry");
		
        int def = 42;

        if (!set_DWORD(dwmKey, opacityValue, def))
            return FALSE;
        if (!exists_DWORD(dwmKey, opacityValue))
            return FALSE;

        opacity = settings.opacity = def;
        writeColorizationBalance(0x08, 0x2b, 0x31);
    }
	
    loadColorValues(readColor());
	old = current;

    return TRUE;
}

BOOL Wh_ModSettingsChanged(BOOL* bReload)
{
    Wh_Log(L"Settings changed");

    *bReload = TRUE;
    return TRUE;
}

BOOL Wh_ModInit()
{
    std::wstring username = read_SZ(L"Volatile Environment", L"USERNAME", L"???");
    if (username == L"???") {
        Wh_Log(L"Local username not detected, stopping now");
        return FALSE;
    }

    winVer = getWinVer();
    if (winVer == WinVersion::None) {
        Wh_Log(L"Invalid OS version");
        return FALSE;
    }
    switch (winVer) {
		case WinVersion::Unsupported:
			Wh_Log(L"Cannot run on Windows 8.1 or earlier");
			return FALSE;

		default:
			break;
    }

    if (!LoadSettings()) {
        Wh_Log(L"Failed to load settings");
        return FALSE;
    }

    HMODULE hDui = LoadLibraryW(L"dui70.dll");
    if (hDui) {
        if (!WindhawkUtils::HookSymbols(hDui, dui70dll_hooks, ARRAYSIZE(dui70dll_hooks))) {
            Wh_Log(L"Failed to hook symbols from dui70.dll");
            return FALSE;
        }
    } else {
        Wh_Log(L"Failed to load dui70.dll");
        return FALSE;
    }

    HMODULE hThemeUi = LoadLibraryW(L"themeui.dll");
    if (hThemeUi) {
        if (!WindhawkUtils::HookSymbols(hThemeUi, themeuidll_hooks, ARRAYSIZE(themeuidll_hooks))) {
            Wh_Log(L"Failed to hook symbols from themeui.dll");
            return FALSE;
        }
    } else {
        Wh_Log(L"Failed to load themeui.dll");
        return FALSE;
    }

    setColorizationBalance();
    return TRUE;
}
