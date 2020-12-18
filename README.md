# Looping Threads in Qt

## Building:

`cmake -B build`

`cmake --build build`

## Examples

### Example 1

`./build/example1`

This demonstrates how to create an object that has an affinity for a specific
thread and "lives" there. The `LoopWorker` is moved to the thread and has a
slot that is triggered on thread starting and is scheduled for deletion on
the thread finishing.

Its problem is we can not exit it because it never yields within the loop.

### Example 2

`./build/example2`

We decide to fix this problem by introducing a boolean variable in the loop
that can be externally modified by a the `stop` slot.

The only reason why we
have to introduce the `LoopManager` is because it is neater to use the stop
slot via a connection rather than using an atomic boolean, thus requiring
maintaining a reference on the LoopWorker after it is created.

The `exit` function call is necessary to stop the thread because otherwise it
would sit with an empty event queue indefinitely.
