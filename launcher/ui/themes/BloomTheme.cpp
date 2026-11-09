// SPDX-License-Identifier: GPL-3.0-only
/*
 *  Bloom Launcher - Minecraft Launcher (based on Prism Launcher)
 *  Copyright (C) 2026 Bloom Launcher Contributors
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, version 3.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "BloomTheme.h"

#include <QObject>

QString BloomTheme::id()
{
    return "bloom";
}

QString BloomTheme::name()
{
    return QObject::tr("Bloom");
}

QString BloomTheme::tooltip()
{
    return QObject::tr("Dark gaming theme of Bloom Launcher");
}

QPalette BloomTheme::colorScheme()
{
    QPalette bloomPalette;
    bloomPalette.setColor(QPalette::Window, QColor(21, 18, 31));
    bloomPalette.setColor(QPalette::WindowText, QColor(236, 232, 245));
    bloomPalette.setColor(QPalette::Base, QColor(16, 13, 24));
    bloomPalette.setColor(QPalette::AlternateBase, QColor(27, 23, 40));
    bloomPalette.setColor(QPalette::ToolTipBase, QColor(34, 29, 51));
    bloomPalette.setColor(QPalette::ToolTipText, QColor(236, 232, 245));
    bloomPalette.setColor(QPalette::PlaceholderText, QColor(125, 117, 150));
    bloomPalette.setColor(QPalette::Text, QColor(236, 232, 245));
    bloomPalette.setColor(QPalette::Button, QColor(36, 31, 54));
    bloomPalette.setColor(QPalette::ButtonText, QColor(236, 232, 245));
    bloomPalette.setColor(QPalette::BrightText, QColor(255, 107, 138));
    bloomPalette.setColor(QPalette::Light, QColor(58, 49, 86));
    bloomPalette.setColor(QPalette::Midlight, QColor(46, 39, 69));
    bloomPalette.setColor(QPalette::Mid, QColor(36, 31, 54));
    bloomPalette.setColor(QPalette::Dark, QColor(12, 10, 19));
    bloomPalette.setColor(QPalette::Shadow, QColor(0, 0, 0));
    bloomPalette.setColor(QPalette::Link, QColor(255, 138, 194));
    bloomPalette.setColor(QPalette::LinkVisited, QColor(196, 140, 255));
    bloomPalette.setColor(QPalette::Highlight, QColor(255, 95, 162));
    bloomPalette.setColor(QPalette::HighlightedText, Qt::white);
    return fadeInactive(bloomPalette, fadeAmount(), fadeColor());
}

double BloomTheme::fadeAmount()
{
    return 0.5;
}

QColor BloomTheme::fadeColor()
{
    return QColor(21, 18, 31);
}

bool BloomTheme::hasStyleSheet()
{
    return true;
}

QString BloomTheme::appStyleSheet()
{
    return QString::fromUtf8(R"QSS(
/* Bloom Launcher - "Bloom" theme: night violet, pink accents, big green Play button */

QToolTip {
    color: #ece8f5;
    background-color: #221d33;
    border: 1px solid #ff5fa2;
    border-radius: 6px;
    padding: 4px 8px;
}

QMainWindow::separator {
    background: #15121f;
    width: 4px;
    height: 4px;
}

/* ---------- Toolbars and tool buttons ---------- */

QToolBar {
    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #1f1933, stop: 1 #16121f);
    border: none;
    spacing: 4px;
    padding: 4px;
}

QToolBar::separator {
    background: #2e2745;
    width: 1px;
    height: 1px;
    margin: 6px;
}

QToolButton {
    color: #ece8f5;
    background: transparent;
    border: 1px solid transparent;
    border-radius: 8px;
    padding: 5px 8px;
}

QToolButton:hover {
    background-color: rgba(255, 95, 162, 32);
    border: 1px solid rgba(255, 95, 162, 120);
}

QToolButton:pressed,
QToolButton:checked {
    background-color: rgba(255, 95, 162, 60);
    border: 1px solid rgba(255, 95, 162, 150);
}

QToolButton:disabled {
    color: #6f6a80;
}

/* ---------- TLauncher-style bottom bar with the big Play button ---------- */

QToolBar#bloomPlayBar {
    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #1c1630, stop: 1 #110e1b);
    border-top: 1px solid #3a2f57;
    padding: 8px 16px;
    spacing: 14px;
}

QLabel#bloomInstanceLabel {
    color: #ffd6ea;
    font-size: 15px;
    font-weight: bold;
}

QToolButton#bloomPlayButton {
    color: #0f2408;
    font-size: 16px;
    font-weight: bold;
    min-width: 200px;
    min-height: 40px;
    padding: 6px 22px;
    border: 1px solid #a8f57a;
    border-radius: 12px;
    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #95ec5f, stop: 1 #45a526);
}

QToolButton#bloomPlayButton:hover {
    border: 1px solid #d4ffb5;
    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #b0f77f, stop: 1 #52bb30);
}

QToolButton#bloomPlayButton:pressed {
    background: #3c901f;
}

QToolButton#bloomPlayButton:disabled {
    color: #77708c;
    border: 1px solid #2e2745;
    background: #221d33;
}

QToolButton#bloomPlayButton[popupMode="1"] {
    padding-right: 34px;
}

QToolButton#bloomPlayButton::menu-button {
    border: none;
    border-left: 1px solid rgba(15, 36, 8, 90);
    border-top-right-radius: 12px;
    border-bottom-right-radius: 12px;
    width: 28px;
}

/* ---------- Buttons ---------- */

QPushButton {
    color: #ece8f5;
    background-color: #241f36;
    border: 1px solid #352d4f;
    border-radius: 8px;
    padding: 5px 14px;
    min-height: 18px;
}

QPushButton:hover {
    background-color: #2c2542;
    border: 1px solid #ff5fa2;
}

QPushButton:pressed {
    background-color: #1b1728;
}

QPushButton:checked {
    background-color: rgba(255, 95, 162, 60);
}

QPushButton:default {
    border: 1px solid #ff5fa2;
}

QPushButton:disabled {
    color: #6f6a80;
    border: 1px solid #2a2538;
}

/* ---------- Inputs ---------- */

QLineEdit,
QAbstractSpinBox,
QComboBox,
QPlainTextEdit,
QTextEdit {
    color: #ece8f5;
    background-color: #100d18;
    border: 1px solid #352d4f;
    border-radius: 6px;
    padding: 3px 6px;
    selection-background-color: #ff5fa2;
    selection-color: #ffffff;
}

QLineEdit:focus,
QAbstractSpinBox:focus,
QComboBox:focus,
QPlainTextEdit:focus,
QTextEdit:focus {
    border: 1px solid #ff5fa2;
}

QLineEdit:disabled,
QAbstractSpinBox:disabled,
QComboBox:disabled {
    color: #6f6a80;
}

/* line edits that live inside combo boxes and spin boxes must stay frameless */
QComboBox QLineEdit,
QAbstractSpinBox QLineEdit {
    border: none;
    border-radius: 0px;
    background: transparent;
    padding: 0px;
}

QComboBox QAbstractItemView {
    background-color: #1b1728;
    border: 1px solid #352d4f;
    selection-background-color: rgba(255, 95, 162, 110);
    selection-color: #ffffff;
}

QAbstractItemView {
    selection-background-color: rgba(255, 95, 162, 110);
    selection-color: #ffffff;
}

/* ---------- Menus ---------- */

QMenuBar {
    background-color: #15121f;
}

QMenuBar::item {
    background: transparent;
    padding: 4px 10px;
    border-radius: 6px;
}

QMenuBar::item:selected {
    background-color: rgba(255, 95, 162, 56);
}

QMenu {
    background-color: #1b1728;
    border: 1px solid #352d4f;
    padding: 4px;
}

QMenu::item {
    padding: 5px 24px 5px 24px;
    border-radius: 6px;
}

QMenu::item:selected {
    background-color: rgba(255, 95, 162, 64);
}

QMenu::item:disabled {
    color: #6f6a80;
}

QMenu::separator {
    height: 1px;
    background: #2e2745;
    margin: 4px 8px;
}

/* ---------- Tabs ---------- */

QTabWidget::pane {
    border: 1px solid #2e2745;
    border-radius: 8px;
}

QTabBar::tab {
    color: #b9b2cc;
    background: #1b1728;
    border: 1px solid #2e2745;
    border-bottom: 2px solid transparent;
    border-top-left-radius: 8px;
    border-top-right-radius: 8px;
    padding: 6px 14px;
    margin-right: 2px;
}

QTabBar::tab:selected {
    color: #ffffff;
    background: #2a2340;
    border-bottom: 2px solid #ff5fa2;
}

QTabBar::tab:hover:!selected {
    color: #ffffff;
}

/* ---------- Scroll bars ---------- */

QScrollBar:vertical {
    background: transparent;
    width: 11px;
    margin: 0px;
}

QScrollBar:horizontal {
    background: transparent;
    height: 11px;
    margin: 0px;
}

QScrollBar::handle:vertical {
    background: #3a3156;
    border-radius: 4px;
    min-height: 32px;
    margin: 2px;
}

QScrollBar::handle:horizontal {
    background: #3a3156;
    border-radius: 4px;
    min-width: 32px;
    margin: 2px;
}

QScrollBar::handle:vertical:hover,
QScrollBar::handle:horizontal:hover {
    background: #ff5fa2;
}

QScrollBar::add-line:vertical,
QScrollBar::sub-line:vertical {
    height: 0px;
}

QScrollBar::add-line:horizontal,
QScrollBar::sub-line:horizontal {
    width: 0px;
}

QScrollBar::add-page,
QScrollBar::sub-page {
    background: none;
}

/* ---------- Progress, sliders, status bar ---------- */

QProgressBar {
    color: #ece8f5;
    background-color: #100d18;
    border: 1px solid #352d4f;
    border-radius: 6px;
    text-align: center;
}

QProgressBar::chunk {
    border-radius: 5px;
    background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 0, stop: 0 #ff5fa2, stop: 1 #b46cff);
}

QSlider::groove:horizontal {
    height: 6px;
    background: #2a2340;
    border-radius: 3px;
}

QSlider::sub-page:horizontal {
    background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 0, stop: 0 #ff5fa2, stop: 1 #b46cff);
    border-radius: 3px;
}

QSlider::handle:horizontal {
    background: #ff5fa2;
    width: 16px;
    margin: -5px 0px;
    border-radius: 8px;
}

QStatusBar {
    background-color: #100d18;
}

QStatusBar::item {
    border: none;
}

/* ---------- Headers and group boxes ---------- */

QHeaderView::section {
    color: #cfc8e2;
    background-color: #1b1728;
    border: none;
    border-right: 1px solid #2e2745;
    border-bottom: 1px solid #2e2745;
    padding: 4px 8px;
}

QGroupBox {
    border: 1px solid #2e2745;
    border-radius: 8px;
    margin-top: 14px;
    padding-top: 8px;
}

QGroupBox::title {
    subcontrol-origin: margin;
    subcontrol-position: top left;
    left: 10px;
    padding: 0px 4px;
    color: #ff8ac2;
}
)QSS");
}
