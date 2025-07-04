<!-- Header with wave -->
<p align="center">
  <img src="https://capsule-render.vercel.app/api?type=waving&color=00BFFF&height=200&section=header&text=C%20Console%20Calendar&fontSize=35&fontColor=ffffff" />
</p>

<!-- GIF / Demo -->
<p align="center">
  <img src="https://media.giphy.com/media/f9XgHHfvXe5dO/giphy.gif" width="300" alt="calendar demo"/>
</p>

<h2 align="center">🗓️ Console Calendar in C</h2>

<p align="center">
  A clean and interactive terminal-based calendar viewer built in <b>C</b>. Navigate months, view today's date in red, and get a feel for C's power with system-level features!
</p>

---

## 🧠 Features

- 📅 Displays monthly calendar with current date highlighted.
- 🔁 Navigate to previous and next months.
- 🧠 Leap year handling.
- 🖥️ Cross-platform logic (Windows `cls` used).
- 🎯 Uses **Zeller’s Congruence** to calculate the starting weekday.

---

## 🖥️ Preview

<p align="center">
  <img width="304" height="301" alt="Console Preview" src="https://github.com/user-attachments/assets/28178d58-841d-4944-84c4-7bea4bc40762" />
</p>

---

## 🧑‍💻 Code Highlight

```c
if (date == today->tm_mday && month == today->tm_mon && year == (today->tm_year + 1900))
    printf("\x1b[31m%2d\x1b[0m ", date); // Red highlight for today
