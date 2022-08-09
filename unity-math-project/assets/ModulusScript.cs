using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ModulusScript : MonoBehaviour {

	public int modulus = 5;
	public int target = 500;
	// Use this for initialization
	void Start () {
		for (int i = 0; i < target; i++) {
			if (i % modulus == 0) {
				Debug.Log (i.ToString () + " is a multiple of " + modulus.ToString ());
			}
		}
		
	}
	
	// Update is called once per frame
	void Update () {
		
	}
}
