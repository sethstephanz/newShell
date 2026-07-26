# newShell

A small Unix shell written in C

The goal of this project is to review Unix process management, system calls,
and boundary between userspace and OS.

## Goals

- Build functional Unix shell
- Understand process creation and execution
- Understand file descriptors and I/O
- Review Unix IPC mechanisms
- Improve C systems programming skills

## Current Status

- [x] Project scaffold
- [x] Build system
- [x] Parser module stub
- [ ] Shell loop
- [ ] Command representation
- [ ] Process execution
- [ ] Built-in commands
- [ ] Redirection
- [ ] Pipes
- [ ] Background processes
- [ ] Signal handling
- [ ] Job control

## Design Notes

### Parser

Responsible for transforming user input into representation
that the shell can interpret.

### Executor

Responsible for running commands and interacting with the OS.

### Builtins

Commands that must execute inside the shell process.

## Questions / Things to Learn/Review

- Why did Unix separate fork() and exec()?
- What state is copied during fork()?
- What state survives exec()?
- How do file descriptors work?
- How do pipes connect processes?
- How does the shell interact with the kernel?

## Build

Instructions for building newShell.

## Notes

Anything interesting learned while working on the project.
