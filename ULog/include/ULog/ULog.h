/*******************************************************************************
 * The MIT License (MIT)
 * 
 * Copyright (c) 2016 Jean-David Gadina - www-xs-labs.com
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
 * @header      ULog.h
 * @copyright   (c) 2016, Jean-David Gadina - www.xs-labs.com
 */

#ifndef ULOG_H
#define ULOG_H

#include <ULog/Macros.h>

/* C++ API */
#ifdef __cplusplus
#include <ULog/CXX/Log.hpp>
#include <ULog/CXX/Message.hpp>
#include <ULog/CXX/Logger.hpp>
#endif

/* Objective-C API */
#ifdef __OBJC__
#import <ULog/OBJC/Message.h>
#import <ULog/OBJC/Logger.h>
#import <ULog/OBJC/LogWindowController.h>
#import <ULog/OBJC/Settings.h>
#import <ULog/OBJC/SettingsWindowController.h>
#endif

/* C API */
#if !defined( __cplusplus ) && !defined( __OBJC__ )
#include <ULog/Base.h>
#include <ULog/C/Log.h>
#endif

#endif /* ULOG_H */
