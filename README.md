# Gameplay Ability System Combat Project

Welcome to my Gameplay Ability System Combat Project, a Sekiro-inspired combat project built with Unreal Engine 5.8 and C++. The project is a demonstration of combat and gameplay systems built around Epic Games' Gameplay Ability System (GAS), AI systems, and other gameplay features that are currently planned or under development.

This project is part of my journey learning the Unreal Engine 5 ecosystem, C++, and Blueprints through self-directed study and the Tom Looman Unreal Engine 5 C++ course.

The main goal of the project is to build a strong understanding of the Gameplay Ability System and learn how to design solid gameplay architectures and maintainable codebases. Another important goal is learning how to build systems that are not only technically robust, but also easy for other team members to use and extend. Where appropriate, gameplay systems will expose functionality through Blueprint, allowing artists and other non-programming team members to configure or implement elements such as VFX and SFX without needing to modify the underlying C++ code.

# Project Features

* Third-person melee character movement
* **Enhanced Input**
* Shared character base for player and AI
* Custom `AnimInstance` implemented in C++ and shared by player and AI
* **Gameplay Ability System**

  * AttributeSet
  * Gameplay Abilities (Sword Attack, Evade, Sprint, Death...)
  * Gameplay Effects
  * Gameplay Tags
* C++ & Blueprint integration
* Sword combat animation set
* 1v1 duel AI using Behavior Trees

# Planned / WIP

* Light attack montages with upper-body layering
* Posture, parry, and block system
* Lock-on and directional strafe movement

I intentionally want to keep the planned feature list limited until the main gameplay combat loop is finished. I am still learning GAS, and its learning curve is significant, so my current focus is on understanding the system deeply and building a solid foundation rather than continuously adding more features.

# Credits

The sword animation pack was created by 9CG. The pack contains raw animations, which has given me the opportunity to learn how to build a basic combat animation setup, integrate the animations into Unreal Engine, and fine-tune them for the project.
