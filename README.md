# Blade

A third-person melee combat vertical slice built with Unreal Engine 5.8 and the Gameplay Ability System (GAS). Work in progress — this description will be updated as the project evolves.

## Project Features

Third-person Melee Character Movement
Enhanced Input (Epic axis convention: Y = forward, X = right)
Orient-to-movement locomotion (`RotationRate` 500)
Walk / Run speeds calibrated to root-motion animation samples (163 / 430 cm/s)
Jump, fall loop, and landing states in Animation Blueprint state machine
1D locomotion Blend Space (speed-driven ground movement)
Cached pose output ready for upper-body montage slots
`UBladeAnimInstance` with thread-safe updates (designed for reuse by player and AI)
Gameplay Ability System foundation
`UAbilitySystemComponent` on Pawn (`InitAbilityActorInfo` in `PossessedBy`)
`UBladeAttributeSet` (Health, MaxHealth, Posture, MaxPosture — posture over stamina)
`ABladeCharacterBase` with `IAbilitySystemInterface` (shared machinery for player and AI)
Mix of C++ & Blueprint for core logic and animation tuning
9CG sword animation skeleton with weapon bones and attach sockets

Planned / WIP
Roll GameplayAbility (montage, cooldown GE, `State.Rolling` tag)
Unlimited sprint (hold Shift — movement toggle, not a GAS ability)
Combat stance (`Idle` ↔ `Idle_Combat`, directional combat locomotion BS)
Light attack montages with upper-body slot on cached pose
Posture / parry / block system via Gameplay Effects
1v1 duel AI (Behavior Tree + Blackboard, abilities activated by tag)
Lock-on with strafe and 2D directional Blend Space
