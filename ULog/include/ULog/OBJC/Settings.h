/*******************************************************************************
 * The MIT License (MIT)
 * 
 * Copyright (c) 2016 Jean-David Gadina - www.xs-labs.com
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 ******************************************************************************/

/*!
 * @header      Settings.h
 * @copyright   (c) 2016, Jean-David Gadina - www.xs-labs.com
 */

#ifndef ULOG_OBJC_SETTINGS_H
#define ULOG_OBJC_SETTINGS_H

#if !defined( TARGET_OS_IOS ) || TARGET_OS_IOS == 0

#if defined( __has_feature ) && __has_feature( objc_modules )
@import Cocoa;
#else
#import <Cocoa/Cocoa.h>
#endif

#define ULOG_HEXCOLOR( c, a )   [ NSColor   colorWithDeviceRed: ( ( CGFloat )( ( c >> 16 ) & 0x0000FF ) ) / ( CGFloat )255  \
                                            green:              ( ( CGFloat )( ( c >>  8 ) & 0x0000FF ) ) / ( CGFloat )255  \
                                            blue:               ( ( CGFloat )( ( c       ) & 0x0000FF ) ) / ( CGFloat )255  \
                                            alpha:              ( CGFloat )a                                                \
                                ]

FOUNDATION_EXPORT NSString * const ULogSettingsKeyFontName;
FOUNDATION_EXPORT NSString * const ULogSettingsKeyFontSize;
FOUNDATION_EXPORT NSString * const ULogSettingsKeyBackgroundColor;
FOUNDATION_EXPORT NSString * const ULogSettingsKeyForegoundColor;
FOUNDATION_EXPORT NSString * const ULogSettingsKeyTimeColor;
FOUNDATION_EXPORT NSString * const ULogSettingsKeySourceColor;
FOUNDATION_EXPORT NSString * const ULogSettingsKeyLevelColor;
FOUNDATION_EXPORT NSString * const ULogSettingsKeyMessageColor;
FOUNDATION_EXPORT NSString * const ULogSettingsKeyShowC;
FOUNDATION_EXPORT NSString * const ULogSettingsKeyShowCXX;
FOUNDATION_EXPORT NSString * const ULogSettingsKeyShowOBJC;
FOUNDATION_EXPORT NSString * const ULogSettingsKeyShowOBJCXX;
FOUNDATION_EXPORT NSString * const ULogSettingsKeyShowASL;
FOUNDATION_EXPORT NSString * const ULogSettingsKeyShowEmergency;
FOUNDATION_EXPORT NSString * const ULogSettingsKeyShowAlert;
FOUNDATION_EXPORT NSString * const ULogSettingsKeyShowCritical;
FOUNDATION_EXPORT NSString * const ULogSettingsKeyShowError;
FOUNDATION_EXPORT NSString * const ULogSettingsKeyShowWarning;
FOUNDATION_EXPORT NSString * const ULogSettingsKeyShowNotice;
FOUNDATION_EXPORT NSString * const ULogSettingsKeyShowInfo;
FOUNDATION_EXPORT NSString * const ULogSettingsKeyShowDebug;

FOUNDATION_EXPORT NSString * const ULogSettingsNotificationDefaultsChanged;
FOUNDATION_EXPORT NSString * const ULogSettingsNotificationDefaultsRestored;

@interface ULogSettings: NSObject

@property( atomic, readwrite, strong ) NSString * fontName;
@property( atomic, readwrite, assign ) CGFloat    fontSize;
@property( atomic, readwrite, strong ) NSColor  * backgroundColor;
@property( atomic, readwrite, strong ) NSColor  * foregoundColor;
@property( atomic, readwrite, strong ) NSColor  * timeColor;
@property( atomic, readwrite, strong ) NSColor  * sourceColor;
@property( atomic, readwrite, strong ) NSColor  * levelColor;
@property( atomic, readwrite, strong ) NSColor  * messageColor;
@property( atomic, readwrite, assign ) BOOL       showC;
@property( atomic, readwrite, assign ) BOOL       showCXX;
@property( atomic, readwrite, assign ) BOOL       showOBJC;
@property( atomic, readwrite, assign ) BOOL       showOBJCXX;
@property( atomic, readwrite, assign ) BOOL       showASL;
@property( atomic, readwrite, assign ) BOOL       showEmergency;
@property( atomic, readwrite, assign ) BOOL       showAlert;
@property( atomic, readwrite, assign ) BOOL       showCritical;
@property( atomic, readwrite, assign ) BOOL       showError;
@property( atomic, readwrite, assign ) BOOL       showWarning;
@property( atomic, readwrite, assign ) BOOL       showNotice;
@property( atomic, readwrite, assign ) BOOL       showInfo;
@property( atomic, readwrite, assign ) BOOL       showDebug;

+ ( instancetype )sharedInstance;
- ( void )restoreDefaults;

@end

#endif

#endif /* ULOG_OBJC_SETTINGS_H */
