import sys
from PyQt6.QtCore import QUrl, Qt
from PyQt6.QtWidgets import QApplication, QMainWindow, QToolBar, QLineEdit, QTabWidget
from PyQt6.QtGui import QAction
from PyQt6.QtWebEngineWidgets import QWebEngineView


class BrowserTab(QWebEngineView):
    def __init__(self, url="https://www.google.com"):
        super().__init__()
        self.setUrl(QUrl(url))


class Browser(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("A FUCKING MULTI TAB ON TOP BROWSER")
        self.resize(1000, 700)

        self.tabs = QTabWidget()
        self.tabs.setTabsClosable(True)
        self.tabs.tabCloseRequested.connect(self.close_tab)
        self.setCentralWidget(self.tabs)
        self.tabs.currentChanged.connect(self.update_url_bar)

        self.toolbar = QToolBar("Navigation")
        self.addToolBar(self.toolbar)

        back_action = QAction('<-', self)
        back_action.triggered.connect(lambda: self.tabs.currentWidget().back())
        self.toolbar.addAction(back_action)

        forward_action = QAction('->', self)
        forward_action.triggered.connect(lambda: self.tabs.currentWidget().forward())
        self.toolbar.addAction(forward_action)

        reload_action = QAction('Refresh', self)
        reload_action.triggered.connect(lambda: self.tabs.currentWidget().reload())
        self.toolbar.addAction(reload_action)

        self.url_bar = QLineEdit()
        self.url_bar.returnPressed.connect(self.load_url)
        self.toolbar.addWidget(self.url_bar)

        self.on_top_action = QAction("OnTop", self)
        self.on_top_action.setCheckable(True)
        self.on_top_action.triggered.connect(self.toggle_on_top)
        self.toolbar.addAction(self.on_top_action)

        self.create_shortcuts()

        self.add_tab("https://www.google.com")

    def add_tab(self, url="https://www.google.com"):
        tab = BrowserTab(url)
        index = self.tabs.addTab(tab, "New Tab")
        self.tabs.setCurrentIndex(index)

        tab.titleChanged.connect(lambda title, tab=tab: self.update_tab_title(tab, title))

    def close_tab(self, index):
        if self.tabs.count() > 1:
            self.tabs.removeTab(index)

    def load_url(self):
        url = self.url_bar.text().strip()
        if not url.startswith(("http://", "https://")):
            url = "https://" + url
        self.tabs.currentWidget().setUrl(QUrl(url))

    def update_url_bar(self, index):
        tab = self.tabs.currentWidget()
        if tab:
            self.url_bar.setText(tab.url().toString())

    def update_tab_title(self, tab, title):
        index = self.tabs.indexOf(tab)
        if index >= 0:
            self.tabs.setTabText(index, title)

    def toggle_on_top(self):
        is_checked = self.on_top_action.isChecked()
        self.setWindowFlag(Qt.WindowType.WindowStaysOnTopHint, is_checked)
        self.show()

    def create_shortcuts(self):
        new_tab_action = QAction(self)
        new_tab_action.setShortcut("Ctrl+T")
        new_tab_action.triggered.connect(lambda: self.add_tab())
        self.addAction(new_tab_action)

        close_tab_action = QAction(self)
        close_tab_action.setShortcut("Ctrl+W")
        close_tab_action.triggered.connect(lambda: self.close_tab(self.tabs.currentIndex()))
        self.addAction(close_tab_action)

        reload_action = QAction(self)
        reload_action.setShortcut("Ctrl+R")
        reload_action.triggered.connect(lambda: self.tabs.currentWidget().reload())
        self.addAction(reload_action)

def main():
    app = QApplication(sys.argv)
    window = Browser()
    window.show()
    sys.exit(app.exec())


if __name__ == "__main__":
    main()
