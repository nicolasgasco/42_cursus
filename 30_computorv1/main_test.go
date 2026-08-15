package main

import "testing"

func TestValidateArgsRejectsZeroArgs(t *testing.T) {
	err := validateArgs([]string{})
	if err == nil {
		t.Fatal("expected an error when 0 arguments are passed")
	}
}

func TestValidateArgsAllowsExactlyOneArg(t *testing.T) {
	err := validateArgs([]string{"arg"})
	if err != nil {
		t.Fatalf("expected no error for exactly 1 argument, got %v", err)
	}
}

func TestValidateArgsRejectsMoreThanOneArg(t *testing.T) {
	err := validateArgs([]string{"first", "second"})
	if err == nil {
		t.Fatal("expected an error when more than 1 argument is passed")
	}
}
