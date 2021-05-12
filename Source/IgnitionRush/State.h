// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PlayerStateInput.h"
#include "PlayerStateMachine.h"
#include "CoreMinimal.h"

/**
 * 
 */
class IGNITIONRUSH_API State
{
public:
	State(UPlayerStateMachine& machine) : stateMachine(machine) {};
	~State();

	UPlayerStateMachine& stateMachine;

	virtual void Init(PlayerStateInput& stateInput) {};
	
	virtual void Enter(PlayerStateInput& stateInput) {};

	virtual void Exit(PlayerStateInput& stateInput) {};

	virtual void Tick(PlayerStateInput& stateInput) {};

	virtual void PhysicsTick(float SubstepDeltaTime, PlayerStateInput& stateInput) {};

};