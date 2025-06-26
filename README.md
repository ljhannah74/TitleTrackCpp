# 🧾 TitleTrackCpp
![Platform](https://img.shields.io/badge/platform-linux%20%7C%20windows-lightgrey)
![License](https://img.shields.io/github/license/ljhannah74/TitleTrackCpp)
![Build](https://img.shields.io/github/actions/workflow/status/ljhannah74/TitleTrackCpp/cmake.yml?label=build)

**TitleTrackCpp** is a cross-platform desktop application for managing real estate abstract reports. Built with **C++**, **wxWidgets**, and **SQLite**, it allows title researchers and abstractors to create, organize, and maintain detailed title report records locally and offline.

---

## 🎯 Features

- View a list of saved abstract reports
- Create new abstracts via a modal form
- Store abstract data in a local SQLite database
- [Planned] Edit and delete existing records
- [Planned] Attach supporting documents and images
- [Planned] Generate reports using templates

---

## 🛠️ Technologies

- **Language:** C++17 or newer
- **GUI Framework:** [wxWidgets](https://www.wxwidgets.org/)
- **Database:** [SQLite](https://www.sqlite.org/)
- **Build System:** [CMake](https://cmake.org/)
- **Platform:** Linux, Windows, macOS (targeting all)

---

## 🚀 Getting Started

### Prerequisites

- C++17-compatible compiler (e.g. GCC, Clang, MSVC)
- wxWidgets (development libraries installed)
- CMake 3.15+
- SQLite3 development libraries

### Build Instructions

```bash
git clone https://github.com/ljhannah74/TitleTrackCpp.git
cd TitleTrackCpp

mkdir build && cd build
cmake ..
make

./TitleTrackCpp
