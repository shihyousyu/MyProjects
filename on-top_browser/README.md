# On-Top-Browser
A lightweight PyQt6 browser built on November 17, 2025. This project was created out of pure frustration when Spotify's mini-player failed me; I needed a browser that stays "On Top" while I work.

## Features
* **Multi-Tab Support:** Open, close, and manage multiple tabs.
* **"OnTop" Toggle:** A dedicated button to trigger `WindowStaysOnTopHint`.
* **Keyboard Shortcuts:**
    * `Ctrl + T`: New Tab
    * `Ctrl + W`: Close Current Tab
    * `Ctrl + R`: Refresh Page
* **Navigation:** Back, Forward, Reload, and a functional URL bar.

## Tech Stack
* **Language:** Python 3.x
* **Framework:** PyQt6
* **Engine:** QtWebEngine (Chromium-based)

## Getting Started

### Prerequisites

You need Python installed and the following dependencies:

```bash
pip install PyQt6 PyQt6-WebEngine

```

### Running the App

```bash
python main.py
```