# The Social Network

A lightweight console-based **The Social Network Simulation** built in C++ using object-oriented programming principles. The application models the core behavior of a social platform including Users, Pages, Posts, Comments, Likes, Memories, and Timelines.

## Features

* **User and Page Creation**
* **Post Sharing** with timestamp
* **Commenting** on posts
* **Liking** posts
* **Timeline Viewing** (User/Page)
* **Memories** from past posts
* **Friend & Page Associations**
* **Custom Date Handling** (with support for relative time like "1h", "2y ago")

This is a command-line application aimed at practicing and demonstrating OOP concepts like inheritance, composition, dynamic memory management, and polymorphism.

---

## Getting Started

### Prerequisites

* A C++ compiler with C++11 (or later) support

  * Recommended: **g++**, **clang++**, or **MSVC**
* Basic understanding of terminal commands
* A C++ IDE or editor like **Visual Studio**, **Code::Blocks**, or **VS Code**

---

## Compilation

You can compile using any C++ compiler. For example, using g++:

```bash
g++ main.cpp -o social_network
./social_network
```

Make sure to include all `.cpp` and `.h` files if your project is split across multiple files.

---

## Project Structure (Simplified)

* `Helper` class for string operations
* `Date` class for handling post and memory timestamps
* `Obj` base class for `User` and `Page`
* `Post` and `Memory` classes
* `Comment` class for post discussion
* `User` and `Page` classes with timelines

---

## How It Works

* Each `Post` is shared by a `User` or `Page`, and contains:

  * Text
  * Date
  * Comments
  * Likes
* Each `Memory` is linked to an original `Post` and can be reshared.
* Timelines store up to 10 posts (can be extended).

---

## Example Output

```txt
PageXYZ - Timeline:
PageXYZ(13/6/2025)
    "Check out our new product!"

        User123: "Amazing!"
        User456: "Love it!"

~~~ User123 shared a memory ~~~ (1h)
    "Throwback to our launch day!"
    ~~~ 2 years ago ~~~
    PageXYZ(13/6/2023)
        "Welcome to our community!"
```

---

## Notes

* Timeline memory is currently limited to 10 entries for simplicity.
* Strings are handled manually using C-strings (`char*`) instead of `std::string` to reinforce low-level memory concepts.

---

## To Do (Suggestions)

* Add `User` and `Page` friend linking
* Save and load all data from external files
* Refactor to use `std::string` and STL containers
* GUI using libraries like Qt or WxWidgets *(Optional)*

---

## License

This project is for educational purposes only. Feel free to use and modify it for your learning.
