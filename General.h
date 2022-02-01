#pragma once

int usage_message(char* program);

enum UserInputs {
	Success = 0,
	InvalidNumArgs,
	InvalidInput
};

enum Inputs {
	Filename = 0,
	Program = 1,
	NumArgs = 2
};