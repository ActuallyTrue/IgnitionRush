// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PlayerStateInput.h"
#include "PlayerStateMachine.h"
#include "PlayerCharacter.h"
#include "CoreMinimal.h"

/**
 * 
 */
class IGNITIONRUSH_API State
{
public:
	State(UPlayerStateMachine& machine, APlayerCharacter& player) : stateMachine(machine), player(player) {};
	~State();

	UPlayerStateMachine& stateMachine;
	APlayerCharacter& player;

	virtual void Init(PlayerStateInput& stateInput) {};
	
	virtual void Enter(PlayerStateInput& stateInput) {};

	virtual void Exit(PlayerStateInput& stateInput) {};

	virtual void Tick(PlayerStateInput& stateInput, float DeltaTime) {};

	virtual void PhysicsTick(float SubstepDeltaTime, PlayerStateInput& stateInput) {};

};