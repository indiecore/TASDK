#pragma once

void InitLogging();
void OutputLog( const char * message, ... );
void InitLoggingTo( const char *log_name );
void OutputLogTo( const char *log_name, const char * message, ... );