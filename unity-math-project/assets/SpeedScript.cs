using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SpeedScript : MonoBehaviour {

	public float speed = 10;
	
	// Update is called once per frame
	void Update () {
		// FRAME PER SECOND
		this.transform.position = new Vector3 (transform.position.x,
			transform.position.y, transform.position.z + speed * Time.deltaTime);
	}
}
