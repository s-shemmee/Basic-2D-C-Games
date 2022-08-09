using UnityEngine;
using System.Collections;

public class HonkScript : MonoBehaviour {

	AudioSource audioSource;
	public AudioClip clip;
	bool alreadyHonked = false;
	// Use this for initialization
	void Start () {
		audioSource = GetComponent<AudioSource> ();
	
	}
	
	// Update is called once per frame
	void Update () {
	
	}

	void OnTriggerEnter(Collider other){
		if (other.gameObject.tag == "Player" ) {
			//if (alreadyHonked == false) {
			//	alreadyHonked = true;
				audioSource.PlayOneShot (clip);
			//}
		}
	}
}
