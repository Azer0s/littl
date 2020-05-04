# 🔥👌 littl

## A small, procedural/semi-functional language

Originally this language was written for a school assignment, now the reiterated version of it serves as a poc for Persephone. We have variables, which we can declare with `var`. There is shorthand declaration with the `:=` operator (which doesn't require a var keyword). There are a couple of datatypes: `fun`, `u8`, `i8`, `u16`, `i16`, `u32`, `i32`, `u64`, `i64`, `f32`, `f64`, `bool` and `void` (void is actually a type and is useful when dealing with void pointers which refer to memory without specific type information).

Littl also has C-style comparison and mathematical operators. Values can be returned with the `return` keyword.

### Use it

```bash
git clone https://github.com/Azer0s/littl.git
cd littl
make
make run path/to/file
```

## Basic syntax

### Functions

```kotlin

fun add(x u8, y u8) u16 {
    return x + y
}

```

### Comparison

is, not | Equality

`<,<=,>,>=` | Greater/Smaller

### String concatenations

```go
print("Hello" <> "World!")
```

### Labels

```go
start:
print("Hello")
goto start
```

### Structs

```go
struct Car {
    make string
    name string
}

var myCar struct::Car = {
    name: "R8"
    make: "Audi"
}

print(myCar->make)
```

### Pointers & casts

By default, memory is automatically managed, you can, however, allocate memory dynamically if so desired.
The `[]` just provides offset for a pointer. The allocated memory will still be garbage collected.

```go
arr := malloc(size(int) * 4).(int*)

arr[0] = 42 //same as writing 4[arr]

var arrPtr int** = addr(arr)
```

### While loops

```kotlin
while isTrue?() {
    print("Hello")
}
```

### For loops

```kotlin
@import("stdlib")
@import("stdio")

for var i u8 in 0..10 {
    print(i)
}

a := malloc(size(int) * 10)

//len is a shorthand for size(a) / size(int)
for var i u32 in 0..len(a) {
    print(itoa(a[0]))
}
```

### If condition

```go
a := 5

if a < 10 {
    print("a is smaller than 10")
} else {
    if a > 21 {
        print("a is bigger than 21")
    } else {
        print("a is bigger than 10")
    }
}

```

These statements have C-like blocks (curly brackets).

Since Littl transpiles to JavaScript, one can use JavaScript functions like `console.log`.

A recursive fibonacci sequence would look like so:

```kotlin
fun fib(n u8) u32 {
    if n is 0 or n is 1 {
        return n
    }

    return fib(n-1) + fib(n-2)
}

x := fib(12)

print(x)
```

Littl also supports anonymous functions
```kotlin
addFn := fun (y fun|u8|u16, x u8) u16 {
    return y(x)
}

foo := addFn(fun(i u8) u16 {
    return x + 3
}, 3)

fun add200(i u8) u16 {
    return i + 200
}

var add fun|i32,i32|i32
add = fun(a i32, b i32) i32 {
    return a + b
}

print(foo) //6
print(addFn(add200, 55)) //255
print(add(10,-5)) //5
```
