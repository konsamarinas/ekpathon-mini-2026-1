# 🏆 EKPATHON mini — 1st Place

**Three hours. Four students. C only. Zero AI. One winning team.**

We participated in EKPATHON mini, a student hackathon organized at the Department of Informatics and Telecommunications of the National and Kapodistrian University of Athens (NKUA).

Our challenge was to extend an existing OASA public transportation application with an original, useful, and feasible third feature — under strict constraints and a three-hour deadline.

**Our team won 1st place among 10 participating teams.**

<p align="center">
  <img src="assets/ekpathon-trophy.jpg" alt="Our team celebrating first place at EKPATHON mini with the winner's trophy" width="700">
</p>

## ⚡ The Challenge

We were given an existing terminal-based public transportation application written in C, featuring:

- Bus departure schedules.
- Estimated bus arrival times at selected stops.

Our task was to design and implement an entirely new feature of our own choosing.

The challenge was designed to be approachable for first-year students while rewarding innovation, usefulness, and practical implementation.

### The Constraints

- ⏱️ **3 hours** to develop our solution.
- 💻 **C only** — no alternative programming languages.
- 🚫 **Strictly no AI assistance** for any purpose.
- 💡 An original feature that adds meaningful value to the existing application.

No AI-generated code. No ready-made AI solutions. Just our team, our ideas, and the code we wrote.

## 💡 Our Solution: Community-Powered Bus Reviews

We developed a passenger feedback system that allows users to rate their bus experience across three categories:

- **Crowding** — How crowded was the bus?
- **Personnel** — How would you rate the personnel?
- **Vehicle Condition** — What was the condition of the bus?

Each category receives a score from 1 to 10. The application calculates an overall average, saves the report locally, and allows users to review previously submitted reports.

To encourage continued participation, we also implemented a prototype reward mechanism that notifies users when they reach ten reports.

Our idea was simple: public transportation information should go beyond schedules and arrival times. Passenger experiences can provide another perspective on the quality of a journey.

## 🛠️ What We Built

- Interactive reporting through a terminal interface.
- Bus line and stop selection using the existing application.
- Three-category passenger ratings and average score calculation.
- Local report persistence using a text file.
- Report history displayed directly in the application.
- A prototype contribution-based reward mechanism.

The implementation was built in C and integrated into the existing project.

## 🥇 The Result

**1st place out of 10 teams.**

In just three hours, we turned an open-ended challenge into a working feature and presented our solution to a panel of academic judges.

Winning was a rewarding recognition of our team's ability to combine an original idea with practical implementation under tight constraints.

## 👥 The Team

A team of four students collaborating across software development, development support, and presentation.

**My contribution:** Software development and implementation of the reporting feature in C, working alongside a teammate who supported the coding process.

The rest of our team focused on presenting the solution and communicating its value to the judges.

## 📂 Project Repository

This repository contains our implementation of the third feature, built on top of the original EKPATHON mini starter project.

- **Original starter repository:** [steliosrotas/ekpathon-mini-1](https://github.com/steliosrotas/ekpathon-mini-1)
- **Language:** C
- **Storage:** Local text file (`reports.txt`)

The project was developed as part of a time-limited educational competition, rather than as a production-ready transportation service.

---

*Three hours of problem-solving. One team effort. One first-place finish.* 🏆
