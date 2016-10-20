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
 * @file        Message.mm
 * @copyright   (c) 2016, Jean-David Gadina - www.xs-labs.com
 */

#include <ULog/ULog.h>

@interface ULogMessage()
{
    ULog::Message _cxxMessage;
}

@property( atomic, readwrite, assign ) ULog::Message    cxxMessage;
@property( atomic, readwrite, assign ) ULogMessageLevel level;
@property( atomic, readwrite, strong ) NSString       * levelString;
@property( atomic, readwrite, strong ) NSString       * message;

@end

@implementation ULogMessage

- ( instancetype )init
{
    return [ super init ];
}

- ( instancetype )initWithCXXMessage: ( const ULog::Message & )message
{
    if( ( self = [ super init ] ) )
    {
        self.cxxMessage = message;
    }
    
    return self;
}

- ( instancetype )initWithLevel: ( ULogMessageLevel )level message: ( NSString * )message
{
    ULog::Message::Level l;
    
    switch( level )
    {
        case ULogMessageLevelEmergency: l = ULog::Message::LevelEmergency; break;
        case ULogMessageLevelAlert:     l = ULog::Message::LevelAlert;     break;
        case ULogMessageLevelCritical:  l = ULog::Message::LevelCritical;  break;
        case ULogMessageLevelError:     l = ULog::Message::LevelError;     break;
        case ULogMessageLevelWarning:   l = ULog::Message::LevelWarning;   break;
        case ULogMessageLevelNotice:    l = ULog::Message::LevelNotice;    break;
        case ULogMessageLevelInfo:      l = ULog::Message::LevelInfo;      break;
        case ULogMessageLevelDebug:     l = ULog::Message::LevelDebug;     break;
        
        break;
    }
    
    return [ self initWithCXXMessage: ULog::Message( l, std::string( message.UTF8String ) ) ];
}

- ( instancetype )initWithLevel: ( ULogMessageLevel )level format: ( NSString * )format, ...
{
    va_list       ap;
    ULogMessage * message;
    
    va_start( ap, format );
    
    message = [ self initWithLevel: level format: format arguments: ap ];
    
    va_end( ap);
    
    return message;
}

- ( instancetype )initWithLevel: ( ULogMessageLevel )level format: ( NSString * )format arguments: ( va_list )ap
{
    return [ self initWithLevel: level message: [ [ NSString alloc ] initWithFormat: format arguments: ap ] ];
}

- ( instancetype )copyWithZone: ( nullable NSZone * )zone
{
    ULogMessage * message;
    
    message = [ [ ULogMessage allocWithZone: zone ] initWithCXXMessage: self.cxxMessage ];
    
    return message;
}

- ( ULog::Message )cxxMessage
{
    @synchronized( self )
    {
        return _cxxMessage;
    }
}

- ( void )setCxxMessage: ( ULog::Message )message
{
    @synchronized( self )
    {
        _cxxMessage         = message;
        self.levelString    = [ NSString stringWithUTF8String: message.GetLevelString().c_str() ];
        self.message        = [ NSString stringWithUTF8String: message.GetMessage().c_str() ];
        
        switch( message.GetLevel() )
        {
            case ULog::Message::LevelEmergency: self.level = ULogMessageLevelEmergency; break;
            case ULog::Message::LevelAlert:     self.level = ULogMessageLevelAlert;     break;
            case ULog::Message::LevelCritical:  self.level = ULogMessageLevelCritical;  break;
            case ULog::Message::LevelError:     self.level = ULogMessageLevelError;     break;
            case ULog::Message::LevelWarning:   self.level = ULogMessageLevelWarning;   break;
            case ULog::Message::LevelNotice:    self.level = ULogMessageLevelNotice;    break;
            case ULog::Message::LevelInfo:      self.level = ULogMessageLevelInfo;      break;
            case ULog::Message::LevelDebug:     self.level = ULogMessageLevelDebug;     break;
            
            break;
        }
    }
}

- ( NSString * )description
{
    NSString * description;
    
    description = [ super description ];
    
    return [ description stringByAppendingFormat: @" %@: %@", self.levelString, self.message ];
}

- ( BOOL )isEqualToMessage: ( ULogMessage * )message
{
    if( message == NULL || [ message isKindOfClass: [ ULogMessage class ] ] == NO )
    {
        return NO;
    }
    
    return self.cxxMessage == message.cxxMessage;
}

- ( BOOL )isEqual: ( id )object
{
    if( object == self )
    {
        return YES;
    }
    
    if( [ object isKindOfClass: [ ULogMessage class ] ] == NO )
    {
        return NO;
    }
    
    return [ self isEqualToMessage: ( ULogMessage * )object ];
}

- ( BOOL )isEqualTo: ( id )object
{
    return [ self isEqual: object ];
}

- ( NSUInteger )hash
{
    return [ NSString stringWithFormat: @"%@ %@", self.levelString, self.message ].hash;
}

@end
