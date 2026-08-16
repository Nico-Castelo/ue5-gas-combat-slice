# Blade — Gameplay Ability System Combat Project

A Sekiro-inspired melee combat project built with Unreal Engine 5.8 and C++. It's a demonstration of combat and gameplay systems built around Epic's Gameplay Ability System. The project is actively in development.

This project is part of my journey learning the Unreal Engine 5 ecosystem, C++, and Blueprints through self-directed study and the Tom Looman Unreal Engine 5 C++ course.

The main goal of the project is to build a strong understanding of the Gameplay Ability System and learn how to design solid gameplay architectures and maintainable codebases. Another important goal is learning how to build systems that are not only technically robust, but also easy for other team members to use and extend. Where appropriate, gameplay systems expose functionality through Blueprint — montages, Gameplay Effects, and later VFX or SFX — simulating working with artists and other non-programmers so they can configure those pieces without modifying the underlying C++ code.

# Project Features

* Third-person melee character movement
* **Enhanced Input**
* Shared character base for player and AI
* Custom `AnimInstance` implemented in C++ and shared by player and AI
* WeaponTraceComponent - Actor component to enable traces and send gameplay events
* **Gameplay Ability System**
  * AttributeSet (Health, Posture, MoveSpeed)
  * Light attack — animation notifies open a hit window; socket-based weapon traces apply damage through a Gameplay Effect
  * Block — blocked hits deal posture damage instead of health. Both Gameplay Effects are always applied; tag requirements decide which one lands (For now)
  * Hit reactions
  * Evade — dodge montage with root motion
  * Sprint — held ability that overrides movement speed through a Gameplay Effect
* Upper-body layering on block hit (torso reacts, legs keep locomotion)
* C++ & Blueprint integration
* Sword combat animation set
* 1v1 duel AI using Behavior Trees — the AI uses the same Gameplay Abilities as the player. The Behavior Tree decides when, the ability decides what. It also blocks reactively when threatened.

# Planned / WIP

* Combos
* Parry / deflect
* Posture break
* Executions
* Lock-on and directional strafe movement (in progress)

I intentionally want to keep the planned feature list limited until the main gameplay combat loop is finished. I prefer a polished core loop first and then keep adding sekiro-like features.

# Credits

The sword animation pack was created by 9CG. The pack contains raw animations, which has given me the opportunity to learn how to build a basic combat animation setup, integrate the animations into Unreal Engine, and fine-tune them for the project. It is a paid asset pack and is not included in this repository.
