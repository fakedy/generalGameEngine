#pragma once
#include<iostream>

enum Level
{
	ERROR,
	WARNING,
	INFO
};


// Logs a message to the console
void Log(Level level, const char* msg);