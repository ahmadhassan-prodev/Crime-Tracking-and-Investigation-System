#pragma once
#include "Crime.h"
#include "Suspect.h"
#include "Evidence.h"

enum ActionType {
    ADD_CRIME,
    DELETE_CRIME,
    ADD_SUSPECT,
    DELETE_SUSPECT,
    ADD_EVIDENCE,
    DELETE_EVIDENCE
};

class Action {
public:
    ActionType type;

    Crime crimeData;
    Suspect suspectData;
    Evidence evidenceData;

    int relatedCrimeID; // for evidence linkage

    Action() {}

    // Crime action
    Action(ActionType t, Crime c) {
        type = t;
        crimeData = c;
    }

    // Suspect action
    Action(ActionType t, Suspect s) {
        type = t;
        suspectData = s;
    }

    // Evidence action
    Action(ActionType t, Evidence e, int crimeID) {
        type = t;
        evidenceData = e;
        relatedCrimeID = crimeID;
    }
};
