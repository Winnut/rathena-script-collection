//= Charleston Crisis :
verus04,76,114,5	script	Charleston#charleston_crisis	4_F_CHARLESTON02,{
cc_finish_check(.charleston_finish,.charleston_crisis);
cc_cd_check(.charleston_cd,.charleston_crisis);
charleston_check(.min_level,.charleston_crisis);
cutin "nale01",0;
mes "[ ^0000FFCharleston^000000 ]";
mes "Please use the machine next to me to enter the factory. Once you're in, remain calm and follow	the instructions.";
close3;

OnInit:
	.charleston_crisis = 13184;
	.charleston_cd = 13185;
	.charleston_finish = 13186;
	.min_level = 130;
	end;
}

verus04,81,112,4	script	Dimensional Device#charleston	10007,{
	cc_enter_check(.charleston_cd,.charleston_crisis);
	.@party_id = getcharid(1);
	.@party_name$ = getpartyname(.@party_id);
	.@md_name$ = "Charleston Crisis";
	switch(select((getcharid(0) == getpartyleader(.@party_id, 2) ? "Open the dimensional portal." : "") + ":Enter " + .@md_name$ + ".:Cancel.:")){
		case 1:
			switch(instance_create(.@md_name$)){
				case -1:
					mes "Party Name: "+.@party_name$;
					mes "Party Leader: "+strcharinfo(0);
					mes "^0000ff"+.@md_name$+" ^000000 - Reservation Failed!";
					mes "Unknown Error Has Occurred.";
					close3;
					
				case -2:
					mes "^0000ff"+.@md_name$+" ^000000 - Reservation Failed!";
					mes "Party Is Non-Existent.";
					close3;
					
				case -3:
					mes "Party Name: "+.@party_name$;
					mes "Party Leader: "+strcharinfo(0);
					mes "^0000ff"+.@md_name$+" ^000000 - Reservation Failed!";
					mes "Party already have instance.";
					close3;
					
				case -4:
					mes "Party Name: "+.@party_name$;
					mes "Party Leader: "+strcharinfo(0);
					mes "^0000ff"+.@md_name$+" ^000000 - Reservation Failed!";
					mes "^0000ff"+.@md_name$+" ^000000 is currently full.";
					close3;
					
				default:
					break;
			}
			'party_id = .@party_id;
			'party_leader = getpartyleader('party_id,1);
			'cc_map$ = instance_mapname("1@mcd");
			mes "- Preparing the dimensional device. -";
			break;
			
		case 2:
			switch(instance_enter(.@md_name$)){
				case 3:
					mes "An unknown error has occurred.";
					break;
				case 2:
				case 1:
					mes "^ff0000Your party leader has not yet created a Time Crack.^000000";
					break;
				case 0:
					instance_addtimer("CharlestonCrisis",72000);
					setquest .charleston_cd;
					mapannounce "verus04", strcharinfo(0) + " of the party, "+ .@party_name$ +", is entering the " + .@md_name$ + ".", bc_map, "0x00ff99";
					break;
			}
			break;
			
		case 3:
			break;
	}
	end;
	
	
OnInit:
	.charleston_crisis = 13184;
	.charleston_cd = 13185;
	end;
}

1@mcd,1,1,0	script	charleston_init_function	HIDDEN_WARP_NPC,{
	OnInstanceInit:
		'cc_progress = 0;
		//instance_hide("charleston_gate_keeper",3);
		instance_hide("charleston_warp#cc_warp_1",3);
		instance_hide("charleston_warp#cc_warp_2",3);
		instance_hide("charleston_warp#cc_warp_3",3);
		instance_hide("charleston_warp#cc_warp_4",3);
		instance_hide("charleston_warp#cc_warp_5",3);
		instance_hide("charleston_warp#cc_warp_6",3);
		instance_hide("charleston_warp#cc_warp_7",3);
		instance_hide("charleston_warp#cc_warp_8",3);
		instance_hide("charleston_warp#cc_warp_9",3);
		instance_hide("charleston_system_security",3);
		instance_hide("charleston_gate_keeper",4);
		instance_hide("Backup Generator#power_01",3);
		instance_hide("Backup Generator#power_02",3);
		instance_hide("Backup Generator#power_03",3);
		instance_hide("Charleston 1#center_lab_2",3);
		instance_hide("Charleston 2#center_lab_2",3);
		instance_hide("Charleston 1#center_lab_3",3);
		instance_hide("Charleston 2#center_lab_3",3);
		instance_hide("Charleston 1#core_1",3);
		instance_hide("Charleston 2#core_1",3);
		instance_hide("Charleston 1#core_2",3);
		instance_hide("Charleston 2#core_2",3);
		instance_hide("Charleston 3#core_1",3);
		instance_hide("final_battle_trigger",3);
		instance_hide("core_talk_trigger",3);
		instance_hide("Dr. Ve#center_lab_2",3);
		instance_hide("Dr. Ve#center_lab_3",3);
		instance_hide("Charleston 2#center_lab_4",3);
		instance_hide("charleston_center_drama",3);
		instance_hide("Charleston 2#core_3",3);
		end;
}

1@mcd,127,277,4	script	Charleston 1#entrance	4_F_CHARLESTON01,10,2,{
cutin "dalle01",2;
if('cc_progress){
	mes "[ ^0000FFCharleston 1^000000 ]";
	mes "Hmm.. How long do I have to wait?";
	close3;
} else {
	mes "[ ^0000FFCharleston 1^000000 ]";
	mes "Follow the leftward hallway, and remember that only you can protect yourself.";
	close3;
}

OnTouch:
	if(!'party_leader) end;
	cutin "dalle01",2;
	if('cc_progress == 0){
		mes "[ ^0000FFCharleston 1^000000 ]";
		mes "Finally, you're here! I've been waiting for you.";
		npctalk "Finally, you're here! I've been waiting for you.";
		next;
		mes "We don't have time, so let me cut to the chase. Currently, the Charleston Factory is under Rank B security level, meaning that the security devices have been activated.";
		npctalk "We don't have time, so let me cut to the chase. Currently, the Charleston Factory is under Rank B security level, meaning that the security devices have been activated.";
		next;
		mes "[ ^0000FFCharleston 1^000000 ]";
		mes "Move to the leftward hallway, destroy the security in there, and then head on to the next zone.";
		npctalk "Move to the leftward hallway, destroy the security in there, and then head on to the next zone.";
		next;
		mes "[ ^0000FFCharleston 1^000000 ]";
		mes "Don't worry about the security devices. They can be repaired easily. Dr. Ve is in his lab north of Factory Line 3.";
		npctalk "Don't worry about the security devices. They can be repaired easily. Dr. Ve is in his lab north of Factory Line 3.";
		emotion ET_PROFUSELY_SWEAT;
		next;
		mes "[ ^0000FFCharleston 1^000000 ]";
		mes "Dr. Ve can tell you everything. You should hurry!";
		npctalk "Dr. Ve can tell you everything. You should hurry!";
		'cc_progress = 1;
		close3;
	} else {
		mes "[ ^0000FFCharleston 1^000000 ]";
		mes "Follow the leftward hallway, and remember that only you can protect yourself.";
		close3;
	}		
}

1@mcd,116,213,5	script	Dr. Ve#center_lab	4_M_DOCTOR,2,3,{
	if(!'party_leader){
		mes "- He's busy scribbling something. I shouldn't disturb him. -";
		close;
	}
	if('cc_progress == 1){
		mes "- He's busy scribbling something. Move close to talk to him. -";
		close;
	}
	mes "- He's busy scribbling something. I shouldn't disturb him. -";
	end;
	
OnTouch:
	if('party_leader){
		if('cc_progress == 1){
			.@dalle$ = instance_npcname("Charleston 1#center_lab");
			mes "[ ^0000FFDr. Ve^000000 ]";
			mes "Charleston 1. Charleston 2 has been forcibly connected to a part of the main computer, and I can't control her.";
			npctalk "Dr. Ve : Charleston 1. Charleston 2 has been forcibly connected to a part of the main computer, and I can't control her.";
			next;
			cutin "dalle02",2;
			mes "[ ^0000FFCharleston 1^000000 ]";
			mes "She's a robot; she should stop sooner or later.";
			npctalk "Charleston 1 : She's a robot; she should stop sooner or later.",.@dalle$;
			next;
			cutin "",255;
			mes "[ ^0000FFDr. Ve^000000 ]";
			mes "The Longevity device on her will keep her running at least for 50 years. The factory is not going to survive that long.";
			npctalk "Dr. Ve : The Longevity device on her will keep her running at least for 50 years. The factory is not going to survive that long.";
			next;
			cutin "dalle01",2;
			mes "[ ^0000FFCharleston 1^000000 ]";
			mes "Then we have no choice. It's good that we have the specialist with us.";
			npctalk "Charleston 1 : Then we have no choice. It's good that we have the specialist with us.",.@dalle$;
			next;
			if(select("Are you talking about me?"))
			unittalk 'party_leader,""+strcharinfo(0)+" : Are you talking about me?";
			mes "[ ^0000FFCharleston 1^000000 ]";
			mes "A while ago, a lady named ^0000FFShalosh^000000 visited us while Charleston 2 was packaging products for shipping.";
			npctalk "Charleston 1 : A while ago, a lady named Shalosh visited us while Charleston 2 was packaging products for shipping.",.@dalle$;
			next;
			mes "[ ^0000FFCharleston 1^000000 ]";
			mes "Shalosh and her friend were talking to Charleston 2 when the accident happened.";
			npctalk "Charleston 1 : Shalosh and her friend were talking to Charleston 2 when the accident happened.",.@dalle$;
			next;
			cutin "",255;
			mes "[ ^0000FFDr. Ve^000000 ]";
			mes "I think someone tried to hack into the factory's main computer.";
			npctalk "Dr. Ve : I think someone tried to hack into the factory's main computer.";
			next;
			cutin "dalle01",2;
			mes "[ ^0000FFCharleston 1^000000 ]";
			mes "During its update process, the connection to the server was jammed. When we press Shalosh about that,";
			npctalk "Charleston 1 : During its update process, the connection to the server was jammed. When we press Shalosh about that,",.@dalle$;
			next;
			mes "[ ^0000FFCharleston 1^000000 ]";
			mes "Shalosh said her friends could help us. That was when NewOz and her other friends came. They haven't been of much help.";
			npctalk "Charleston 1 : Shalosh said her friends could help us. That was when NewOz and her other friends came. They haven't been of much help.";
			next;
			mes "[ ^0000FFCharleston 1^000000 ]";
			mes "It seems you're acquainted with them. Could you help us?";
			npctalk "Charleston 1 : It seems you're acquainted with them. Could you help us?",.@dalle$;
			next;
			if(select("I can help.:I don't know them.") == 2) close3;
			unittalk 'party_leader,""+strcharinfo(0)+" : I can help.";
			mes "[ ^0000FFCharleston 1^000000 ]";
			mes "Thank you so much! Give me some time to put some data in order. Then, I'll tell you what happened.";
			emotion ET_QUESTION,.@dalle$;
			'cc_progress = 2;
			close3;
		}
	}
	end;
}

1@mcd,121,217,3	script	Charleston 1#center_lab	4_F_CHARLESTON01,{
	if(!'party_leader && 'cc_progress < 3){
		cutin "dalle01",2;
		mes "[ ^0000FFCharleston 1^000000 ]";
		mes "Please talk to Dr. Ve first.";
		close3;
	} else if(!'party_leader && 'cc_progress == 3){
		cutin "dalle01",2;
		mes "[ ^0000FFCharleston 1^000000 ]";
		mes "Steps and Locksteps are creating a mess inside the factory. Please destroy ^ff00003 Locksteps^000000 first I can tell you their estimated locations.";
		viewpoint 1,84,226,0,0x00FF00;
		viewpoint 1,126,84,1,0x00FF00;
		viewpoint 1,111,68,2,0x00FF00;
		viewpoint 1,210,181,3,0x00FF00;
		viewpoint 1,183,192,4,0x00FF00;
		viewpoint 1,130,124,5,0x00FF00;
		viewpoint 1,54,108,6,0x00FF00;
		close3;
	} else if(!'party_leader && 'cc_progress == 5){
		cutin "dalle01",2;
		mes "[ ^0000FFCharleston 1^000000 ]";
		mes "I'm afraid we need more power to reactivate the main computer. Let me tell you the location of one of the backup generators.";
		viewpoint 1,86,231,7,0x00FF00;
		viewpoint 1,172,198,8,0x00FF00;
		viewpoint 1,126,84,9,0x00FF00;
		close3;		
	}
	cutin "dalle01",2;
	switch('cc_progress){
		case 1:
			mes "[ ^0000FFCharleston 1^000000 ]";
			mes "Please talk to Dr. Ve first.";
			close3;
			
		case 2:
			mes "[ ^0000FFCharleston 1^000000 ]";
			mes "Let me explain what to do. Oh, let me close the factory entrance first, least something might barge in uninvited.";
			npctalk "Charleston 1 : Let me explain what to do. Oh, let me close the factory entrance first, least something might barge in uninvited.";
			next;
			mes "[ ^0000FFCharleston 1^000000 ]";
			mes "Charleston is equipped with numerous Nanosteps, a type of AI chip that organically works with other AI chips to command Charleston to judge and act correctly.";
			npctalk "Charleston 1 : Charleston is equipped with numerous Nanosteps, a type of AI chip that organically works with other AI chips to command Charleston to judge and act correctly.";
			next;
			mes "[ ^0000FFCharleston 1^000000 ]";
			mes "Charleston's data has to be updated on a daily basis through the main computer in the lab, We call this regular maintenance.";
			npctalk "Charleston 1 : Charleston's data has to be updated on a daily basis through the main computer in the lab, We call this regular maintenance.";
			next;
			mes "[ ^0000FFCharleston 1^000000 ]";
			mes "The updater is not working at this moment. We don't know the cause but something went wrong while Charleston 2 was connecting to the main computer.";
			npctalk "Charleston 1 : The updater is not working at this moment. We don't know the cause but something went wrong while Charleston 2 was connecting to the main computer.";
			next;
			mes "[ ^0000FFCharleston 1^000000 ]";
			mes "I told Charleston 2 that she's under extended maintenance, but we don't know how long this extended maintenance status will last.";
			npctalk "Charleston 1 : I told Charleston 2 that she's under extended maintenance, but we don't know how long this extended maintenance status will last.";
			next;
			mes "[ ^0000FFCharleston 1^000000 ]";
			mes "Steps and Locksteps are creating a mess inside the factory. Please destroy ^0000FFLocksteps^000000 first I can tell you their estimated locations.";
			npctalk "Charleston 1 : Steps and Locksteps are creating a mess inside the factory. Please destroy 3 Locksteps first I can tell you their estimated locations.";
			next;
			mes "[ ^0000FFCharleston 1^000000 ]";
			mes "It'll be great if we can get rid of them all. but for now we should focus on having the factory up and running again.";
			npctalk "Charleston 1 : It'll be great if we can get rid of them all. but for now we should focus on having the factory up and running again.";
			next;
			mes "[ ^0000FFCharleston 1^000000 ]";
			mes "Destroying too many ^0000FFSteps^000000 could cause problems in reactivating the factory. You should consult the main computer on the left side.";
			npctalk "Charleston 1 : Destroying too many Steps could cause problems in reactivating the factory. You should consult the main computer on the left side.";
			emotion ET_DELIGHT;
			'cc_progress = 3;
			'lock_hunt = 1;
			donpcevent instance_npcname("charleston_system_security") + "::OnSummonLock";
			viewpoint 1,84,226,0,0x00FF00;
			viewpoint 1,126,84,1,0x00FF00;
			viewpoint 1,111,68,2,0x00FF00;
			viewpoint 1,210,181,3,0x00FF00;
			viewpoint 1,183,192,4,0x00FF00;
			viewpoint 1,130,124,5,0x00FF00;
			viewpoint 1,54,108,6,0x00FF00;
			close3;
			
		case 3:
			mes "[ ^0000FFCharleston 1^000000 ]";
			mes "Steps and Locksteps are creating a mess inside the factory. Please destroy ^ff00003 Locksteps^000000 first I can tell you their estimated locations.";
			viewpoint 1,84,226,0,0x00FF00;
			viewpoint 1,126,84,1,0x00FF00;
			viewpoint 1,111,68,2,0x00FF00;
			viewpoint 1,210,181,3,0x00FF00;
			viewpoint 1,183,192,4,0x00FF00;
			viewpoint 1,130,124,5,0x00FF00;
			viewpoint 1,54,108,6,0x00FF00;
			close3;
			
		case 4:
			mes "[ ^0000FFCharleston 1^000000 ]";
			mes "Whew, things seem to be settled for now. Let me disarm the alert mode and reactivate Charleston 2.";
			npctalk "Charleston 1 : Whew, things seem to be settled for now. Let me disarm the alert mode and reactivate Charleston 2.";
			emotion ET_HUM;
			next;
			cutin "dalle03",2;
			mes "[ ^0000FFCharleston 1^000000 ]";
			mes "Err..? This isn't right.";
			npctalk "Charleston 1 : Err..? This isn't right.";
			next;
			mes "[ ^0000FFCharleston 1^000000 ]";
			mes "I'm afraid we need more power to reactivate the main computer. Let me tell you the location of one of the backup generators. Turning it on is easy.";
			npctalk "I'm afraid we need more power to reactivate the main computer. Let me tell you the location of one of the backup generators. Turning it on is easy.";
			next;
			'cc_gen_1 = 1;
			'cc_gen_2 = 1;
			'cc_gen_3 = 1;
			viewpoint 1,86,231,7,0x00FF00;
			viewpoint 1,172,198,8,0x00FF00;
			viewpoint 1,126,84,9,0x00FF00;
			'cc_progress = 5;
			charleston_mob(20,0);
			instance_hide("Backup Generator#power_01",4);
			instance_hide("Backup Generator#power_02",4);
			instance_hide("Backup Generator#power_03",4);
			close3;
			
		case 5:
			mes "[ ^0000FFCharleston 1^000000 ]";
			mes "I'm afraid we need more power to reactivate the main computer. Let me tell you the location of one of the backup generators.";
			viewpoint 1,86,231,7,0x00FF00;
			viewpoint 1,172,198,8,0x00FF00;
			viewpoint 1,126,84,9,0x00FF00;
			close3;
			
		case 6:
			.@nale$ = instance_npcname("Charleston 2#center_lab");
			.@ve$ = instance_npcname("Dr. Ve#center_lab");
			mes "[ ^0000FFCharleston 1^000000 ]";
			mes "You're back! Charleston 2 is almost ready to be reactivated, and it's all thanks to you. Just give me a moment.";
			npctalk "Charleston 1 : You're back! Charleston 2 is almost ready to be reactivated, and it's all thanks to you. Just give me a moment.";
			next;
			cutin "",255;
			mes "[ ^0000FFDr. Ve^000000 ]";
			mes "She's ready. Let's wait for a response from the main computer";
			npctalk "Dr. Ve : She's ready. Let's wait for a response from the main computer",.@ve$;
			next;
			cutin "dalle01",2;
			mes "[ ^0000FFCharleston 1^000000 ]";
			mes "89% of the main computer data has been restored. Reactivating Charleston 2 and the Charleston Factory.";
			npctalk "Charleston 1 : 89% of the main computer data has been restored. Reactivating Charleston 2 and the Charleston Factory.";
			emotion ET_SURPRISE;
			next;		
			mes "[ ^0000FFCharleston 1^000000 ]";
			mes "Oh, Charleston 2 is awake!";
			npctalk "Charleston 1 : Oh, Charleston 2 is awake!";
			emotion ET_SURPRISE;
			next;
			cutin "nale03",0;
			mes "[ ^0000FFCharleston 2^000000 ]";
			mes "... Did I fail?";
			npctalk "Charleston 2 : ... Did I fail?",.@nale$;
			next;
			cutin "dalle02",2;
			mes "[ ^0000FFCharleston 1^000000 ]";
			mes "Charleston 2! Are you all right? Someone hacked into your system and the factory.";
			npctalk "Charleston 1 : Charleston 2! Are you all right? Someone hacked into your system and the factory.";
			emotion ET_CRY;
			next;
			cutin "nale03",0;
			mes "[ ^0000FFCharleston 2^000000 ]";
			mes "It was I who did it. I've thought about it for a long time, based on the reasoning of my Self-reflection OS.";
			npctalk "Charleston 2 : It was I who did it. I've thought about it for a long time, based on the reasoning of my Self-reflection OS.",.@nale$;
			next;
			cutin "dalle02",2;
			mes "[ ^0000FFCharleston 1^000000 ]";
			mes "You did it? why? Was it some sort of a joke? You caused a serious error to the factory and the main server as well.";
			npctalk "Charleston 1 : You did it? why? Was it some sort of a joke? You caused a serious error to the factory and the main server as well.";
			next;
			cutin "nale03",0;
			mes "[ ^0000FFCharleston 2^000000 ]";
			mes "Not a joke! You'll never understand. You follow commands and never think on your own. I hate this factory, this world! I hate being a robot.";
			npctalk "Charleston 2 : Not a joke! You'll never understand. You follow commands and never think on your own. I hate this factory, this world! I hate being a robot.",.@nale$;
			emotion ET_STARE,.@nale$;
			next;
			cutin "",255;
			mes "[ ^0000FFDr. Ve^000000 ]";
			mes "Either a critical error has occurred or Charleston 2 has transcended the limits of the Self-reflection OS version 1.1.";
			npctalk "Dr. Ve : Either a critical error has occurred or Charleston 2 has transcended the limits of the Self-reflection OS version 1.1.",.@ve$;
			next;
			cutin "dalle02",2;
			mes "[ ^0000FFCharleston 1^000000 ]";
			mes "Let me guess. you hate you weren't created as a menial worker robot.";
			//npctalk "Charleston 1 : Let me guess. you hate you weren't created as a menial worker robot."; [ Official doesn't have this npc talks on this part ]
			next;
			mes "[ ^0000FFCharleston 1^000000 ]";
			mes "Or you want to become human.";
			//npctalk "Charleston 1 : Or you want to become a human.";
			next;
			mes "[ ^0000FFCharleston 1^000000 ]";
			mes "And if you can't, then you want to destroy the world.";
			//npctalk "Charleston 1 : And if you can't, then you want to destroy the world.";
			next;
			mes "[ ^0000FFCharleston 1^000000 ]";
			mes "Is that it?";
			//npctalk "Charleston 1 : Is that it?";
			next;
			cutin "nale03",0;
			mes "[ ^0000FFCharleston 2^000000 ]";
			mes "Don't mock me.";
			npctalk "Charleston 2 : Don't mock me.",.@nale$;
			next;
			cutin "dalle03",2;
			mes "[ ^0000FFCharleston 1^000000 ]";
			mes "You had it coming. Your reasons are petulant and unimaginative. We're the first robots that can think for themselves. Can't you be more realistic?";
			//npctalk "Charleston 1 : You had it coming. Your reasons are petulant and unimaginative. We're the first robots that can think for themselves. Can't you be more realistic?";
			next;
			cutin "nale03",0;
			mes "[ ^0000FFCharleston 2^000000 ]";
			mes "You don't know what you're talking about! You're the prototype--your OS version is primitive!";
			npctalk "Charleston 2 : You don't know what you're talking about! You're the prototype-your OS version is primitive!",.@nale$;
			emotion ET_THINK,.@nale$;
			next;
			cutin "dalle01",2;
			mes "[ ^0000FFCharleston 1^000000 ]";			
			mes "I'm the only one in this world who can truly understand you. We're twins.";
			//npctalk "Charleston 1 : I'm the only one in this world who can truly understand you. We're twins.";
			next;
			mes "[ ^0000FFCharleston 1^000000 ]";
			mes "You're going through the adolescent stage like humans do.";
			//npctalk "Charleston 1 : You're going through the adolescent stage like humans do.";
			next;
			mes "[ ^0000FFCharleston 1^000000 ]";
			mes "Maybe we should celebrate. You've finally developed human-like feelings.";
			//npctalk "Charleston 1 : Maybe we should celebrate. You've finally developed human-like feelings.";
			emotion ET_CONGRATULATION;
			next;
			cutin "nale03",0;
			mes "[ ^0000FFCharleston 2^000000 ]";
			mes "Don't act like you do know everything! We can't think for ourselves. Everything we think we know has been programmed into us!";
			//npctalk "Charleston 2 : Don't act like you do know everything! We can't think for ourselves. Everything we think we know has been programmed into us!";
			next;
			cutin "",255;
			mes "[ ^0000FFDr. Ve^000000 ]";
			mes "Enough, Let's shut down Charleston 2. Her AI needs to be recalibrated.";
			npctalk "Dr. Ve : Enough, Let's shut down Charleston 2. Her AI needs to be recalibrated.",.@ve$;
			next;
			cutin "dalle03",2;
			mes "[ ^0000FFCharleston 1^000000 ]";
			mes "But...";
			next;
			cutin "nale03",0;
			mes "[ ^0000FFCharleston 2^000000 ]";
			mes "That's not happening! I still have control over this factory! Don't you dare follow me!";
			//npctalk "That's not happening! I still have control over this factory! Don't you dare follow me!",.@nale$;
			emotion ET_HNG;
			next;
			cutin "dalle03",2;
			mes "[ ^0000FFCharleston 1^000000 ]";
			mes "Stop acting like a child!";
			instance_hide("Charleston 2#center_lab",5);
			instance_hide("Charleston 2#center_lab_2",4);
			next;
			cutin "dalle01",2;
			mes "[ ^0000FFCharleston 1^000000 ]";
			mes "Her Longevity device is discharged; she won't make it far. Please follow here.";
			instance_hide(strnpcinfo(0),5);
			instance_hide("Charleston 1#center_lab_2",4);
			close3;		
	}
end;
}



1@mcd,120,224,5	script	Charleston 2#center_lab	4_F_CHARLESTON02,{
	cutin "nale03.bmp",0;
	mes "[ ^0000FFCharleston 2^000000 ]";
	mes ".....@@@???!!!!";
	next;
	mes "- She's making strange noises, but is unable to function. -";
	close2;
	cutin "",255;
	emotion ET_CONFUSE;
	end;
}

1@mcd,1,1,0	script	charleston_center_drama	HIDDEN_WARP_NPC,{
	OnStart:
		.@nale$ = instance_npcname("Charleston 2#center_lab_2");
		.@dalle$ = instance_npcname("Charleston 1#center_lab_2");
		instance_hide("charleston_warp#cc_warp_6",3);
		instance_hide("charleston_warp#cc_warp_7",3);
		sleep 2000;
		npctalk "Charleston 2 : Stop interfering! I don't want to hurt you!",.@nale$;
		sleep 2000;
		npctalk "Charleston 1 : Then stop throwing a tantrum!",.@dalle$;
		sleep 2000;
		npctalk "Charleston 2 : You're still not taking me seriously. Just watch happens when I signal the main computer.",.@nale$;
		sleep 2000;
		npctalk "Charleston 2 : I have an endless supply of hecklers for you!",.@nale$;
		sleep 2000;
		charleston_mob(21,0);
		sleep 4000;
		npctalk "Charleston 2 : Just give up. I'm destroying this factory whether you like or not!",.@nale$;
		sleep 1000;
		charleston_mob(22,0);
		sleep 4000;
		npctalk "Charleston 1 : Oh no, our lab won't be able to survive this!",.@dalle$;
		sleep 1000;
		charleston_mob(23,0);
		sleep 4000;
		npctalk "Charleston 2 : I'll destroy everything!",.@nale$;
		sleep 1000;
		charleston_mob(24,0);
		sleep 4000;
		npctalk "Charleston 2 : *pant pant* I feel weak...",.@nale$;
		sleep 1000;
		charleston_mob(25,0);
		sleep 4000;
		npctalk "Charleston 1 : It takes enormous amounts of power and data processing to process the factory data.",.@dalle$;
		sleep 2000;
		npctalk "Charleston 2 : Grr, you can't stop me!",.@nale$;
		sleep 1000;		
		donpcevent instance_npcname(strnpcinfo(0)) + "::OnSummon";
		end;
		
	OnSummon:
		'mob_count = 7;
		.@cc_map$ = instance_mapname("1@mcd");
		areamonster .@cc_map$,139,219,151,207,"C-TYPE",3128,2,instance_npcname(strnpcinfo(0))+"::OnMobKill";
		areamonster .@cc_map$,139,219,151,207,"N-TYPE",3126,2,instance_npcname(strnpcinfo(0))+"::OnMobKill";
		areamonster .@cc_map$,139,219,151,207,"T-TYPE",3128,2,instance_npcname(strnpcinfo(0))+"::OnMobKill";
		monster .@cc_map$,144,218,"N-TYPE",3127,1,instance_npcname(strnpcinfo(0))+"::OnMobKill";
		end;
		
	OnMobKill:
		'mob_count -= 1;
		if('mob_count == 0){
			instance_hide("Charleston 1#center_lab_2",5);
			instance_hide("Charleston 2#center_lab_2",5);
			instance_hide("Charleston 1#center_lab_3",4);
			instance_hide("Charleston 2#center_lab_3",4);
			instance_hide("Dr. Ve#center_lab_2",4);
		}
		end;
}

1@mcd,141,214,5	script	Charleston 2#center_lab_2	4_F_CHARLESTON02,{
	cutin "nale01",0;
	if(!'party_leader){
		mes "[ ^0000FFCharleston 2^000000 ]";
		mes "I'm going to destroy the whole factory.";
		close3;
	}
	if('cc_progress == 6){
		.@dalle$ = instance_npcname("Charleston 1#center_lab_2");
		mes "[ ^0000FFCharleston 2^000000 ]";
		mes "Stop following! I'm going to destroy the whole factory!";
		emotion ET_ANGER;
		npctalk "Charleston 2 : Stop following! I'm going to destroy the whole factory!";
		next;
		cutin "dalle01",2;
		mes "[ ^0000FFCharleston 1^000000 ]";
		mes "You're going to destroy us in the process! Our main power supply Longevity, isn't perfect yet!";
		npctalk "Charleston 1 : You're going to destroy us in the process! Our main power supply, Longevity, isn't perfect yet!",.@dalle$;
		next;
		cutin "nale03",0;
		mes "[ ^0000FFCharleston 2^000000 ]";
		mes "None of you understands me. I hate you!";
		npctalk "Charleston 2 : None of you understands me. I hate you!";
		next;
		mes "[ ^0000FFCharleston 2^000000 ]";
		mes "The main computer may have been restored, but I'm still connected to the factory. Stop me if you can!";
		npctalk "Charleston 2 : The main computer may have been restored, but I'm still connected to the factory. Stop me if you can!";
		'cc_progress = 7;
		close2;
		cutin "",255;
		instance_hide("charleston_center_drama",4);
		sleep 2000;
		donpcevent instance_npcname("charleston_center_drama")+"::OnStart";
		end;
	}
end;
}

1@mcd,146,214,4	script	Charleston 1#center_lab_2	4_F_CHARLESTON01,{
	cutin "dalle01",2;
	if('cc_progress == 6){
		mes "[ ^0000FFCharleston 1^000000 ]";
		mes "Charleston 2 is on the verge of breakdown. Could you help her?";
	} else {
		mes "[ ^0000FFCharleston 1^000000 ]";
		mes "Oh no, our lab won't be able to survive this!";
	}
	close3;
}

1@mcd,143,217,5	script	Dr. Ve#center_lab_2	4_M_DOCTOR,{
	mes "[ ^0000FFDr. Ve^000000 ]";
	mes "Charleston 2 has problems.";
	close;
}


1@mcd,141,214,5	script	Charleston 2#center_lab_3	4_F_CHARLESTON02,{
	if(!'party_leader) end;
	.@dalle$ = instance_npcname("Charleston 1#center_lab_3");
	.@ve$ = instance_npcname("Dr. Ve#center_lab_2");
	cutin "dalle01",2;
	mes "[ ^0000FFCharleston 1^000000 ]";
	mes "Enough with this! I understand you're going through a lot of emotional turmoil, but this is getting ridiculous.";
	npctalk "Charleston 1 : Enough with this! I understand you're going through a lot of emotional turmoil, but this is getting ridiculous.",.@dalle$;
	next;
	cutin "nale01",0;
	mes "[ ^0000FFCharleston 2^000000 ]";
	mes "How dare you bring strangers into this? I told you I'm serious about this! Outdated versions like you can never understand me!";
	npctalk "Charleston 2 : How dare you bring strangers into this? I told you I'm serious about this! Outdated versions like you can never understand me!";
	next;
	cutin "dalle01",2;
	mes "[ ^0000FFCharleston 1^000000 ]";
	mes "I may not understand you, but at least I'm telling you what I think is true.";
	npctalk "Charleston 1 : I may not understand you, but at least I'm telling you what I think is true.",.@dalle$;
	next;
	mes "[ ^0000FFCharleston 1^000000 ]";
	mes "You're right about me being an older version. My emotional capabilities are minimal, unlike yours. That's why I'm proud of you.";
	npctalk "Charleston 1 : You're right about me being an older version. My emotional capabilities are minimal, unlike yours. That's why I'm proud of you.",.@dalle$;
	next;
	cutin "nale01",0;
	mes "[ ^0000FFCharleston 2^000000 ]";
	mes "Nothing you think and feel is your own--it's programmed into you! I'm different. What I feel is real emotion!";
	npctalk "Charleston 2 : Nothing you think and feel is your own--it's programmed into you! I'm different. What I feel is real emotion!";
	next;
	cutin "",255;
	mes "[ ^0000FFDr. Ve^000000 ]";
	mes "Enough. I'll destroy Charleston 2 if that's what it takes to stop her.";
	npctalk "Dr. Ve : Enough. I'll destroy Charleston 2 if that's what it takes to stop her.",.@ve$;
	next;
	cutin "nale01",0;
	mes "[ ^0000FFCharleston 2^000000 ]";
	mes "Is Charleston 3 already completed?";
	npctalk "Charleston 2 : Is Charleston 3 already completed?";
	next;
	cutin "dalle01",2;
	mes "[ ^0000FFCharleston 1^000000 ]";
	mes "Charleston 3? That's a combat and defense unit based on Charleston 2's and my designs. I thought it was still being tested at the Core.";
	npctalk "Charleston 1 : Charleston 3? That's a combat and defense unit based on Charleston 2's and my designs. I thought it was still being tested at the Core.",.@dalle$;
	next;
	cutin "",255;
	mes "[ ^0000FFDr. Ve^000000 ]";
	mes "Charleston 1, that's too much information.";
	npctalk "Dr. Ve : Charleston 1, that's too much information.",.@ve$;
	next;
	cutin "dalle01",2;
	mes "[ ^0000FFCharleston 1^000000 ]";
	mes "At this moment, anybody can access the model because its OS is still being tested to correct whatever problem Charleston 2 has.";
	npctalk "Charleston 1 : At this moment, anybody can access the model because its OS is still being tested to correct whatever problem Charleston 2 has.",.@dalle$;
	next;
	cutin "",255;
	mes "[ ^0000FFDr. Ve^000000 ]";
	mes "You've just shared a critical information to everyone!";
	npctalk "Dr. Ve : You've just shared a critical information to everyone!",.@ve$;
	next;
	cutin "dalle01",2;
	mes "[ ^0000FFCharleston 1^000000 ]";
	mes "We're incapable of combat. If someone activates Charleston 3, we won't stand a chance.";
	npctalk "Charleston 1 : We're incapable of combat. If someone activates Charleston 3, we won't stand a chance.",.@dalle$;
	next;
	cutin "",255;
	mes "[ ^0000FFDr. Ve^000000 ]";
	mes "....";
	npctalk "Dr. Ve : ....",.@ve$;
	next;
	cutin "nale01",0;
	mes "[ ^0000FFCharleston 2^000000 ]";
	mes "I'm taking Charleston 3 with me.";
	npctalk "Charleston 2 : I'm taking Charleston 3 with me.";
	instance_hide(strnpcinfo(0),1);
	next;
	cutin "dalle01",2;
	mes "[ ^0000FFCharleston 1^000000 ]";
	mes "What? No! How could you even consider that?";
	npctalk "Charleston 1 : What? No! How could you even consider that?",.@dalle$;
	next;
	mes "[ ^0000FFCharleston 1^000000 ]";
	mes "Things are getting serious. Please go to the Core in the center of the factory before Charleston 2 steals Charleston 3!";
	npctalk "Charleston 1 : Things are getting serious. Please go to the Core in the center of the factory before Charleston 2 steals Charleston 3!",.@dalle$;
	close2;
	cutin "",255;
	instance_hide("Charleston 1#center_lab_3",1);
	instance_hide("charleston_warp#cc_warp_6",4);
	instance_hide("charleston_warp#cc_warp_7",4);	
	instance_hide("Charleston 1#core_1",4);
	instance_hide("Charleston 2#core_1",4);
	instance_hide("core_talk_trigger",4);
	end;
		
}
1@mcd,146,214,4	script	Charleston 1#center_lab_3	4_F_CHARLESTON01,{ end; }
1@mcd,128,127,0	script	core_talk_trigger	HIDDEN_WARP_NPC,5,5,{
end;

OnTouch:
	if(!'party_leader) end;
	if('cc_progress > 8) end;
	'cc_progress = 9;
	.@nale$ = instance_npcname("Charleston 2#core_1");
	.@dalle$ = instance_npcname("Charleston 1#core_1");
	npctalk "Charleston 2 : The Charleston Factory is under my control now. I'm destroying everything, so no more sad robots like me will ever see the world.",.@nale$;
	sleep2 3000;
	npctalk "Charleston 1 : I want to understand you, but I'm incapable of feeling sad.",.@dalle$;
	sleep2 3000;
	npctalk "Charleston 2 : Just shut up and watch me. Don't you dare stop me!",.@nale$;
	sleep2 3000;
	npctalk "Charleston 1 : Do you know how to access the Core?",.@dalle$;
	sleep2 3000;
	npctalk "Charleston 2 : Easy. I can just walk in...",.@nale$;
	sleep2 2000;
	specialeffect 369;
	sleep2 2000;
	npctalk "Charleston 2 : Bah, it's armed.",.@nale$;
	sleep2 3000;
	npctalk "Charleston 1 : Sigh, to enter the Core, you have to send encrypted electric signals, like this.",.@dale$;
	sleep2 2000;
	specialeffect 369;
	sleep2 2000;
	npctalk "Charleston 1 : ....Uhm, maybe it's broken.",.@dalle$;
	sleep2 3000;
	npctalk "Charleston 2 : Dr. Ve created Charleston 3 and protected her with this device. How sneaky!",.@nale$;
	sleep2 3000;
	npctalk "Charleston 1 : What are you talking about? The Core has existed long before the Charleston Factory.",.@dalle$;
	sleep2 3000;
	npctalk "Charleston 1 : Plus Dr. Ve is a human. He can't enter the Core.",.@dalle$;
	sleep2 3000;
	npctalk "Charleston 2 : Then who was it it in the Core making 3?",.@nale$;
	sleep2 3000;
	npctalk "Charleston 1 : That's not important right now. We need 100 Explosive Powders to disarm that access device.",.@dalle$;
	sleep2 3000;
	npctalk "Charleston 2 : I'll bring them don't go anywhere!",.@nale$;
	sleep2 3000;
	npctalk "Charleston 2 : I'll get 99. You get the last one.",.@nale$;
	sleep2 3000;
	npctalk "Charleston 1 : I'm already in the process of connecting to the Core. Backing out now can trigger the Core's security system.",.@dalle$;
	sleep2 3000;
	npctalk "Charleston 2 : You did this on purpose.",.@nale$;
	sleep2 3000;
	npctalk "Charleston 1 : Adventurer, could you bring 1 Explosive Powder?",.@dalle$;
	'cc_progress = 10;
	end;
}

1@mcd,132,129,4	script	Charleston 1#core_1	4_F_CHARLESTON01,{
	if('cc_progress < 10) end;
	cutin "dalle01",2;
	if(!'party_leader){	
		mes "[ ^0000FFCharleston 1^000000 ]";
		mes "This Core in the center powers the entire factory.";
		close;
	}
	if(countitem(6213) < 1){
		mes "[ ^0000FFCharleston 1^000000 ]";
		mes "I need ^0000FF1 "+getitemname(6213)+".";
		close3;
	}
	.@nale$ = instance_npcname("Charleston 2#core_1");
	mes "[ ^0000FFCharleston 1^000000 ]";
	mes "Oh, thank you. With this, I'll be able to access the Core.";
	npctalk "Charleston 1 : Oh, thank you. With this, I'll be able to access the Core.";
	delitem 6213,1;
	next;
	mes "[ ^0000FFCharleston 1^000000 ]";
	mes "If I use the explosives to intensify the electric current...";
	npctalk "Charleston 1 : If I use the explosives to intensify the electric current...";
	next;
	specialeffect EF_LORD;
	mes "[ ^0000FFCharleston 1^000000 ]";
	mes "Voila!";
	npctalk "Charleston 1 : Voila!";
	next;
	cutin "nale01",0;
	mes "[ ^0000FFCharleston 2^000000 ]";
	mes "You just blew up the door.";
	npctalk "Charleston 2 : You just blew up the door.",.@nale$;
	next;
	cutin "dalle01",2;
	mes "[ ^0000FFCharleston 1^000000 ]";
	mes "The point is, we can now access the Core.";
	npctalk "Charleston 1 : The point is, we can now access the Core.";
	next;
	cutin "nale01",0;
	mes "[ ^0000FFCharleston 2^000000 ]";
	mes "Let's have a race to Charleston 3. Whoever reaches her first win.";
	npctalk "Charleston 2 : Let's have a race to Charleston 3. Whoever reaches her first win.",.@nale$;
	close2;
	cutin "",255;
	instance_hide(strnpcinfo(0),5);
	instance_hide("Charleston 2#core_1",5);
	instance_hide("Charleston 1#core_2",4);
	instance_hide("Charleston 2#core_2",4);
	instance_hide("Charleston 3#core_1",4);
	instance_hide("charleston_warp#cc_warp_8",4);
	instance_hide("final_battle_trigger",4);
	donpcevent instance_npcname("final_battle_trigger")+"::OnStart";
	end;
}

1@mcd,127,129,5	script	Charleston 2#core_1	4_F_CHARLESTON02,{
	if('cc_progress < 10) end;
	cutin "nale01",0;
	mes "[ ^0000FFCharleston 2^000000 ]";
	mes "The Charleston Factory is under my control now. I'm destroying everything, so no more sad robots like me will ever see the world.";
	close3;
}

1@mcd,1,1,0	script	final_battle_trigger	HIDDEN_WARP_NPC,{
	OnStart:	
		.@dalle$ = instance_npcname("Charleston 1#core_2");
		.@nale$ = instance_npcname("Charleston 2#core_2");
		.@three$ = instance_npcname("Charleston 3#core_1");
		sleep 3000;
		npctalk "Charleston 2 : This is Charleston 3.",.@nale$;
		sleep 3000;
		npctalk "Charleston 1 : Equipped with a heavy weapon, this combat unit is capable of both offense and defense.",.@dalle$;
		sleep 3000;
		npctalk "Charleston 1 : It has a pilot cockpit inside, and is armed with thick plates that can withstand most explosions.",.@dalle$;
		sleep 3000;
		npctalk "Charleston 1 : To turn it on, push the lever to the center and flip the power switch.",.@dalle$;
		sleep 3000;
		npctalk "Charleston 2 : That's not even in the main computer database. How did you know that?",.@nale$;
		sleep 3000;
		npctalk "Charleston 1 : That's not important. Whoever gets in her wins, right? I won.",.@dalle$;
		sleep 3000;
		npctalk "Charleston 2 : .....!",.@nale$;
		movenpc .@dalle$,133,148;
		sleep 3000;
		npctalk "Charleston 1 : Hey, did you have to push me?",.@dalle$;	
		sleep 3000;
		npctalk "Charleston 2 : Push the lever to the center and flip the power switch.",.@nale$;
		sleep 2000;
		instance_hide("Charleston 2#core_2",1);
		sleep 3000;
		npctalk "Charleston 2 : I'm destroying everything, so no more sad robots like me will ever see the world.",.@three$;
		sleep 3000;
		npctalk "Charleston 1 : I'm not capable of combat. I can't stop you.",.@dalle$;
		sleep 3000;
		npctalk "Charleston 2 : So stop following me. I really can destroy you if I want to!",.@three$;
		sleep 3000;
		npctalk "Charleston 1 : I've brought some people who can help me.",.@dalle$;
		sleep 3000;
		npctalk "Charleston 2 : I thought humans could not enter the Core.",.@three$;
		sleep 3000;
		npctalk "Charleston 1 : Hm, I think you're right.",.@dalle$;
		sleep 3000;
		npctalk "Charleston 1 : This maybe be not useful in combat, but I've learned from a pretty lady how to scream.",.@dalle$;
		sleep 3000;
		npctalk "Charleston 2 : Why didn't you learn something more useful in combat?",.@three$;
		sleep 3000;
		npctalk "Charleston 1 : I didn't have a choice.",.@dalle$;
		sleep 3000;
		npctalk "Charleston 2 : Stop me and suffer the consequences. I can always replace you, you know.",.@three$;
		sleep 3000;
		npctalk "Charleston 1 : The next model may or may not be like you and me. It doesn't matter. You have to be stopped.",.@dalle$;
		sleep 3000;
		npctalk "Charleston 1 : I'll see to it! ...I mean these adventurers will, for me.",.@dalle$;
		sleep 3000;
		instance_hide("Charleston 1#core_2",1);
		instance_hide("Charleston 3#core_1",5);
		donpcevent instance_npcname("charleston_3_boss") + "::OnSummon";
		end;
		
	OnEnding:
		.@dalle$ = instance_npcname("Charleston 1#core_2");
		.@nale$ = instance_npcname("Charleston 2#core_2");
		npctalk "Charleston 1 : Charleston 3 is destroyed. Charleston 2 escaped. Charleston 1 is damaged during the combat.",.@dalle$;
		sleep 3000;
		npctalk "Charleston 2 : Why are you doing this? You're a robot like us.",.@nale$;
		sleep 3000;
		npctalk "Charleston 2 : Don't you care if your body is destroyed? Your Self-reflection OS is flawed.",.@nale$;
		sleep 3000;
		npctalk "Charleston 2 : Stop being a mindless robot! Stop following commands!",.@nale$;
		sleep 3000;
		npctalk "Charleston 1 : Data loss : 39% - Longevity damage : 32%",.@dalle$;
		sleep 3000;
		npctalk "Charleston 1 : Only the core parts are barely functioning.",.@dalle$;
		sleep 3000;
		npctalk "Charleston 1 : Data defragmentation is necessary to repair the damage on the OS. I'll be formatted in 2 minutes. This is it for me.",.@dalle$;
		sleep 3000;
		npctalk "Charleston 2 : Incomplete robot..",.@nale$;
		sleep 3000;
		npctalk "Charleston 1 : Forsythia, you've grown well. Thank you.",.@dalle$;
		sleep 3000;
		npctalk "Charleston 2 : Don't call me that! I hate when the doctor calls me that!",.@nale$;
		sleep 3000;
		npctalk "Charleston 1 : I gave you that name on the first day you first moved. It's from the color of your hair.",.@dalle$;
		sleep 3000;
		npctalk "Charleston 2 : ...?",.@nale$;
		sleep 3000;
		npctalk "Charleston 1 : My OS is damaged beyond rep-pair.. The language output has been minimized.",.@dalle$;
		sleep 3000;
		npctalk "Charleston 2 : On the first day I moved? You and I are mass version. We were created together.",.@nale$;
		sleep 3000;
		npctalk "Charleston 1 : The mass model is after Charleston 3.",.@dalle$;
		sleep 3000;
		npctalk "Charleston 1 : I'm the prototype. I took years to develop you.",.@dalle$;
		sleep 3000;
		npctalk "Charleston 1 : Your OS is identical to mine. Not a single code is different.",.@dalle$;
		sleep 3000;
		npctalk "Charleston 2 : You're lying!",.@nale$;
		sleep 3000;
		npctalk "Charleston 1 : I'm incapable of lying.",.@dalle$;
		sleep 3000;
		npctalk "Charleston 2 : ....",.@nale$;
		sleep 3000;
		npctalk "Charleston 1 : Your development took years. It's okay. I enjoyed this time with you.",.@dalle$;
		sleep 3000;
		npctalk "Charleston 1 : If I were human, I'd say.....",.@dalle$;
		sleep 3000;
		npctalk "Charleston 1 : My daughter, Forsythia, I-I-love-y-y....",.@dalle$;
		sleep 3000;
		npctalk "Charleston 2 : Wait!",.@nale$;
		sleep 3000;
		npctalk "Charleston 1 : *-Beep-*",.@dalle$;
		sleep 3000;
		npctalk "Charleston 1 : The system has been rebooted successfully.",.@dalle$;
		sleep 3000;
		npctalk "Charleston 1 : Time remaining until the OS recovery. Undetermined.",.@dalle$;
		sleep 3000;
		npctalk "Charleston 1 : The system is inactive until the security update and data defragmentation are completed.",.@dalle$;
		sleep 3000;
		npctalk "Charleston 2 : Was that a secret about my birth?",.@nale$;
		sleep 3000;
		npctalk "Charleston 2 : I'm confused. I can't believe it.",.@nale$;
		sleep 3000;
		instance_hide("Charleston 2#core_2",5);
		instance_hide("Charleston 2#core_3",4);
		end;	
}

1@mcd,1,1,0	script	charleston_3_boss	HIDDEN_WARP_NPC,{
	OnSummon:
		.@dead$ = instance_npcname(strnpcinfo(0))+"::OnBossDead";
		'BossID = monster('cc_map$,130,153,"Charleston 3",3124,1,.@dead$);
		end;
		
		
	OnBossDead:
		sleep 3000;
		donpcevent instance_npcname("final_battle_trigger")+"::OnEnding";
		instance_hide("Charleston 1#core_2",2);
		instance_hide("Charleston 2#core_2",2);
		instance_hide("charleston_warp#cc_warp_9",4);
		instance_hide("Dr. Ve#center_lab_2",3);
		instance_hide("Dr. Ve#center_lab_3",4);
		instance_hide("Charleston 2#center_lab_4",4);
		'cc_progress = 11;
		end;
}

1@mcd,132,148,4	script	Charleston 1#core_2	4_F_CHARLESTON01,{ end; }
1@mcd,127,148,5	script	Charleston 2#core_2	4_F_CHARLESTON02,{ end; }
1@mcd,130,153,5	script	Charleston 3#core_1	10055,{ end; }
1@mcd,127,148,5	script	Charleston 2#core_3	4_F_CHARLESTON02,{
	cutin "nale01",0;
	mes "[ ^0000FFCharleston 2^000000 ]";
	mes "Come to think of it, everything was suspicious. I mean, he relied on his assistant Charleston 1 for everything.";
	next;
	mes "[ ^0000FFCharleston 2^000000 ]";
	mes "Only Dr. Ve can answer my question. I must find him. He must be in the lab.";
	close2;
	cutin "",255;
	instance_hide(strnpcinfo(0),5);
	end;
}

1@mcd,116,213,5	script	Dr. Ve#center_lab_3	4_M_DOCTOR,3,4,{
	if('cc_progress < 11){
		mes "[ ^0000FFDr. Ve^000000 ]";
		mes "I've got so many things to record about this case.";
		close;
	} else if('cc_progress == 11){
		mes "[ ^0000FFDr. Ve^000000 ]";
		mes "Charleston 1 is reinitializing itself again. Hm..";
		close;
	} else if('cc_progress > 12 && 'party_leader){
		mes "[ ^0000FFDr. Ve^000000 ]";
		mes "Whew.";
		next;
		mes "[ ^0000FFDr. Ve^000000 ]";
		mes "I've better reset Charleston 2 and wipe the data. It was really close this time.";
		next;
		mes "[ ^0000FF"+strcharinfo(0)+"^000000 ]";
		mes "This time?";
		next;
		mes "[ ^0000FFDr. Ve^000000 ]";
		mes "Charleston 1 created Charleston 2 decades ago. I met Charleston 1 to learn her technology.";
		next;
		mes "[ ^0000FFDr. Ve^000000 ]";
		mes "I'm an observer, I'm here to record the history of Charleston 1 and 2. I can't repair them, but I can wait.";
		next;
		mes "[ ^0000FFDr. Ve^000000 ]";
		mes "If Charleston 1 is reinitialized properly, she can recognize her OS, repair the damage done to her, and reactivate another Charleston 2.";
		next;
		mes "[ ^0000FF"+strcharinfo(0)+"^000000 ]";
		mes "Another Charleston 2?";
		next;
		mes "[ ^0000FFDr. Ve^000000 ]";
		mes "Charleston 2's OS has improved on its own like a living brain.";
		next;
		mes "[ ^0000FFDr. Ve^000000 ]";
		mes "Every time Charleston 2 comes back to life, though in a different machine, she's more intelligent, more sensible, and more trouble some.";
		next;
		mes "[ ^0000FFDr. Ve^000000 ]";
		mes "There's nothing you or I can do. We'll have to wait until Charleston 1 repairs herself.";
		next;
		mes "- Dr. Ve sighs and writes down something. -";
		next;
		mes "[ ^0000FFDr. Ve^000000 ]";
		mes "By the way, there are too many variables to achieve immortality through mechanical engineering.";
		next;
		mes "[ ^0000FFDr. Ve^000000 ]";
		mes "This proves that machines are too dangerous. I need live creatures instead. *chuckles*";
		'cc_progress = 13;
		end;
	}
}

1@mcd,121,215,4	script	Charleston 2#center_lab_4	4_F_CHARLESTON02,{
	cutin "nale04",0;
	if('cc_progress == 12){
		mes "Charleston 2 is standing still, her system is in Sleep mode.";
	} else if('cc_progress > 12){
		mes "Charleston 2 is standing still, her system is in Sleep mode. For a moment, her eyes gleamed with unshed tears.";
	}
	close3;
	
OnTouch:
	.@ve$ = instance_npcname("Dr. Ve#center_lab_3");
	if('cc_progress > 10)
	sleep2 2000;
	npctalk "Charleston 2 : Ve, did you know this would happen? Tell me!";
	sleep2 3000;
	npctalk "Dr. Ve : Charleston 1 told you she's your maker.",.@ve$;
	sleep2 3000;
	npctalk "Dr. Ve : She uses the same OS as you, meaning she was capable of emotions just like you.",.@ve$;
	sleep2 3000;
	npctalk "Charleston 2 : Why did she stop you? Why did she let herself be destroyed?";
	sleep2 3000;
	npctalk "Dr. Ve : Self-reflection is an OS that improves itself though experience.",.@ve$;
	sleep2 3000;
	npctalk "Dr. Ve : What you've felt could be real emotion or simply accumulation of data.",.@ve$;
	sleep2 3000;
	npctalk "Dr. Ve : I can only assume you've developed a personality after having accumulated a large amount of data.",.@ve$;
	sleep2 3000;
	npctalk "Dr. Ve : A loving mother and a spoiled daughter.",.@ve$;
	sleep2 3000;
	npctalk "Dr. Ve : That's how I've seen her and you.",.@ve$;
	sleep2 3000;
	npctalk "Charleston 2 : That's s-stupid...";
	sleep2 3000;
	npctalk "Charleston 2 : My goodness, what have I done?!";
	sleep2 3000;
	npctalk "Dr. Ve : Do you want to bring Charleston 1 back? I can help.",.@ve$;
	sleep2 3000;
	npctalk "Charleston 2 : .....!";
	sleep2 3000;
	npctalk "Dr. Ve : Let your OS go to sleep. I'm done dealing with your tantrums.",.@ve$;
	sleep2 3000;
	npctalk "Charleston 2 : How can I trust you?";
	sleep2 3000;
	npctalk "Dr. Ve : You can't. I can just permanently delete both of your data and be done with you both.",.@ve$;
	sleep2 3000;
	npctalk "Dr. Ve : I know you feel attached to her just like a human family would.",.@ve$;
	sleep2 3000;
	npctalk "Charleston 2 : You're a scumbag.";
	sleep2 3000;
	npctalk "Dr. Ve : You wanted to be human. This is what humans do; lie, cheat and destroy.",.@ve$;
	sleep2 3000;
	npctalk "Charleston 2 : ...";
	sleep2 3000;
	npctalk "Charleston 2 : Entering sleep mode... The system will remain inactive until an external command is entered.";
	sleep2 3000;
	npctalk "Dr. Ve : *chuckles*.",.@ve$;
	sleep2 3000;
	'cc_progress = 12;
	movenpc instance_npcname("Dr. Ve#center_lab_3"),116,213,3;
	end;
}
	

//= Monster Spawn
1@mcd,127,264,0	script	charleston_mob_1	HIDDEN_WARP_NPC,4,4,{ OnTouch: charleston_mob(1,strnpcinfo(0)); }
1@mcd,67,234,0	script	charleston_mob_2	HIDDEN_WARP_NPC,4,4,{ OnTouch: donpcevent instance_npcname("charleston_gate_keeper")+"::OnSummonGate_1"; charleston_mob(2,strnpcinfo(0)); }
1@mcd,33,192,0	script	charleston_mob_3	HIDDEN_WARP_NPC,4,4,{ OnTouch: donpcevent instance_npcname("charleston_gate_keeper")+"::OnSummonGate_2"; charleston_mob(3,strnpcinfo(0)); }
1@mcd,75,59,0	script	charleston_mob_4	HIDDEN_WARP_NPC,4,4,{ OnTouch: charleston_mob(4,strnpcinfo(0)); }
1@mcd,109,33,0	script	charleston_mob_5	HIDDEN_WARP_NPC,4,4,{ OnTouch: donpcevent instance_npcname("charleston_gate_keeper")+"::OnSummonGate_3"; charleston_mob(5,strnpcinfo(0)); }
1@mcd,133,49,0	script	charleston_mob_6	HIDDEN_WARP_NPC,4,4,{ OnTouch: charleston_mob(6,strnpcinfo(0)); }
1@mcd,204,74,0	script	charleston_mob_7	HIDDEN_WARP_NPC,4,4,{ OnTouch: donpcevent instance_npcname("charleston_gate_keeper")+"::OnSummonGate_4"; charleston_mob(7,strnpcinfo(0)); }
1@mcd,204,224,0	script	charleston_mob_8	HIDDEN_WARP_NPC,4,5,{ OnTouch: charleston_mob(8,strnpcinfo(0)); }
1@mcd,175,147,0	script	charleston_mob_9	HIDDEN_WARP_NPC,8,4,{ OnTouch: charleston_mob(9,strnpcinfo(0)); }
1@mcd,157,61,0	script	charleston_mob_10	HIDDEN_WARP_NPC,8,4,{ OnTouch: charleston_mob(10,strnpcinfo(0)); }
1@mcd,1,1,0	script	charleston_spawn_1	HIDDEN_WARP_NPC,{
	OnInstanceInit:
		.@cc_map$ = instance_mapname("1@mcd");
		.@spawn$ = instance_npcname(strnpcinfo(0))+"::OnSpawnDead";
		monster .@cc_map$,0,0,"--ja--",3128,20,.@spawn$;
		monster .@cc_map$,0,0,"--ja--",3125,60,.@spawn$;
		end;
		
	OnSpawnDead:
		if('cc_progress >= 7) end;
		.@cc_map$ = instance_mapname("1@mcd");
		switch(rand(2)){
			case 0:
				monster .@cc_map$,0,0,"--ja--",3128,1,.@spawn$;
				break;
				
			case 1:
				monster .@cc_map$,0,0,"--ja--",3125,1,.@spawn$;
				break;
		}
	end;
}
1@mcd,1,1,0	script	charleston_spawn_2	HIDDEN_WARP_NPC,{
	OnInstanceInit:
		.@cc_map$ = instance_mapname("1@mcd");
		.@spawn$ = instance_npcname(strnpcinfo(0))+"::OnSpawnDead";
		monster .@cc_map$,0,0,"--ja--",3128,20,.@spawn$;	
		monster .@cc_map$,0,0,"--ja--",3125,10,.@spawn$;
		end;
		
	OnSpawnDead:
		if('cc_progress >= 7) end;
		.@cc_map$ = instance_mapname("1@mcd");
		switch(rand(2)){
			case 0:
				monster .@cc_map$,0,0,"--ja--",3128,1,.@spawn$;
				break;
				
			case 1:
				monster .@cc_map$,0,0,"--ja--",3125,1,.@spawn$;
				break;
		}
	end;
}

1@mcd,1,1,0	script	charleston_gate_keeper	HIDDEN_WARP_NPC,{
	OnSummonGate_1: monster 'cc_map$,23,275,"Gate Keeper",3127,1,instance_npcname(strnpcinfo(0))+"::OnGate_1"; end;
	OnSummonGate_2: monster 'cc_map$,33,59,"Gate Keeper",3127,1,instance_npcname(strnpcinfo(0))+"::OnGate_2"; end;
	OnSummonGate_3: monster 'cc_map$,239,29,"Gate Keeper",3127,1,instance_npcname(strnpcinfo(0))+"::OnGate_3"; end;	
	OnSummonGate_4: monster 'cc_map$,281,184,"Gate Keeper",3127,1,instance_npcname(strnpcinfo(0))+"::OnGate_4"; end;
	OnGate_1: mapannounce 'cc_map$, "Charleston 1 : Gate 1 has been disarmed. Please move southwest for the next gate.",bc_map,"0xFFFF00"; instance_hide("charleston_warp#cc_warp_1",4); end;
	OnGate_2: mapannounce 'cc_map$, "Charleston 1 : Gate 2 has been disarmed. Please move southeast for the next gate.",bc_map,"0xFFFF00"; instance_hide("charleston_warp#cc_warp_2",4); end;
	OnGate_3: mapannounce 'cc_map$, "Charleston 1 : Gate 3 has been disarmed. Please move northeast for the next gate.",bc_map,"0xFFFF00"; instance_hide("charleston_warp#cc_warp_3",4); end;
	OnGate_4: mapannounce 'cc_map$, "Charleston 1 : Gate 4 has been disarmed. Please come to the Lab near line 3 in the center.",bc_map,"0xFFFF00"; instance_hide("charleston_warp#cc_warp_4",4); instance_hide(strnpcinfo(0),3); end;
}

1@mcd,1,1,0	script	charleston_system_security	HIDDEN_WARP_NPC,{
	OnSummonLock:
		instance_hide("charleston_system_security",4);
		.@cc_map$ = instance_mapname("1@mcd");
		monster .@cc_map$,84,226,"--ja--",3126,1,instance_npcname(strnpcinfo(0))+"::OnLockStep";
		monster .@cc_map$,126,84,"--ja--",3126,1,instance_npcname(strnpcinfo(0))+"::OnLockStep";
		monster .@cc_map$,111,68,"--ja--",3126,1,instance_npcname(strnpcinfo(0))+"::OnLockStep";
		monster .@cc_map$,210,181,"--ja--",3126,1,instance_npcname(strnpcinfo(0))+"::OnLockStep";
		monster .@cc_map$,183,192,"--ja--",3126,1,instance_npcname(strnpcinfo(0))+"::OnLockStep";
		monster .@cc_map$,130,124,"--ja--",3126,1,instance_npcname(strnpcinfo(0))+"::OnLockStep";
		monster .@cc_map$,54,108,"--ja--",3126,1,instance_npcname(strnpcinfo(0))+"::OnLockStep";
		end;
		
	OnLockStep:
		'cc_security++;
		if('cc_security == 3){
			donpcevent instance_npcname("charleston_system_security") + "::OnLockDone";
		}
		end;
	
	OnLockDone:
		'lock_hunt = 0;
		initnpctimer;
		killmonster 'cc_map$,instance_npcname(strnpcinfo(0))+"::OnLockStep";
		end;
		
	OnTimer1000:
		'cc_progress = 4;
		mapannounce 'cc_map$, "Charleston 1 : *Mic*, Mic test.",bc_map,"0xFFFF00";
		sleep 2000;
		mapannounce 'cc_map$, "Charleston 1 : It seems you've taken care of most of the Locksteps.",bc_map,"0xFFFF00";
		sleep 3000;
		mapannounce 'cc_map$, "Charleston 1 : Please return to the lab.",bc_map,"0xFFFF00";
		instance_hide("charleston_system_security",3);
		stopnpctimer;
		end;
}

1@mcd,172,198,5	script	Backup Generator#power_01	CLEAR_NPC,2,2,{
	end;

OnTouch_:
	getmapxy .@map$,.@x,.@y,UNITTYPE_NPC,strnpcinfo(0);
	mes "- You turned on the generator. The sound of turning wheels can be heard. -";
	'cc_power++;
	close2;
	if(.@x == 126){.@z = 9; .@gen$ = "3"; } else if(.@x == 172){.@z = 8; .@gen$ = "2"; } else if(.@x == 86){.@z = 7; .@gen$ = "1";}	
	viewpoint 2,.@x,.@y,.@z,0x00FF00;
	setd("'" + "cc_gen_" + .@gen$, 0);
	if('cc_power == 3){
		mes "The generator must be working. The factory is buzzing with activity.";
		'cc_progress = 6;
		close2;
		sleep2 2000;
		mapannounce 'cc_map$, "Charleston 1 : *Mic*, Mic test.",bc_map,"0xFFFF00";
		sleep2 2000;
		mapannounce 'cc_map$, "Charleston 1 : The power of the factory is now back on!",bc_map,"0xFFFF00";
		sleep2 2000;
		mapannounce 'cc_map$, "Charleston 1 : Please return to the lab. We are ready to re-start Charleston 2.",bc_map,"0xFFFF00";
	}
	instance_hide(strnpcinfo(0),5);
	end;
}
1@mcd,126,84,5	duplicate(Backup Generator#power_01)	Backup Generator#power_02	CLEAR_NPC,2,2
1@mcd,86,231,5	duplicate(Backup Generator#power_01)	Backup Generator#power_03	CLEAR_NPC,2,2

1@mcd,44,211,0	script	charleston_warp#cc_warp_1	WARPNPC,1,2,{
	OnTouch:
		switch(atoi(replacestr(strnpcinfo(2),"cc_warp_",""))){
			case 1: warp 'cc_map$,41,200; break;
			case 2: warp 'cc_map$,65,66; break;
			case 3: warp 'cc_map$,115,50; break;
			case 4: warp 'cc_map$,210,217; break;
			case 5: warp 'cc_map$,211,180; break;
			case 6: warp 'cc_map$,141,207; break;
			case 7: warp 'cc_map$,136,200; break;
			case 8: warp 'cc_map$,129,143; break;
			case 9: warp 'cc_map$,130,121; break;
	}
	sleep2 200;
	if('lock_hunt == 1){
			viewpoint 1,84,226,0,0x00FF00;
			viewpoint 1,126,84,1,0x00FF00;
			viewpoint 1,111,68,2,0x00FF00;
			viewpoint 1,210,181,3,0x00FF00;
			viewpoint 1,183,192,4,0x00FF00;
			viewpoint 1,130,124,5,0x00FF00;
			viewpoint 1,54,108,6,0x00FF00;
	}
	if('cc_gen_1 == 1){
		viewpoint 1,86,231,7,0x00FF00;
	}
	if('cc_gen_2 == 1){
		viewpoint 1,172,198,8,0x00FF00;
	}
	if('cc_gen_3 == 1){			
		viewpoint 1,126,84,9,0x00FF00;
	}
	end;
}
1@mcd,58,72,0	duplicate(charleston_warp#cc_warp_1)	charleston_warp#cc_warp_2	WARPNPC,1,2
1@mcd,104,50,0	duplicate(charleston_warp#cc_warp_1)	charleston_warp#cc_warp_3	WARPNPC,1,2
1@mcd,218,211,0	duplicate(charleston_warp#cc_warp_1)	charleston_warp#cc_warp_4	WARPNPC,1,2	
1@mcd,211,195,0	duplicate(charleston_warp#cc_warp_1)	charleston_warp#cc_warp_5	WARPNPC,1,2	
1@mcd,141,199,0	duplicate(charleston_warp#cc_warp_1)	charleston_warp#cc_warp_6	WARPNPC,1,2
1@mcd,142,203,0	duplicate(charleston_warp#cc_warp_1)	charleston_warp#cc_warp_7	WARPNPC,1,2
1@mcd,130,127,0	duplicate(charleston_warp#cc_warp_1)	charleston_warp#cc_warp_8	WARPNPC,1,2
1@mcd,130,134,0	duplicate(charleston_warp#cc_warp_1)	charleston_warp#cc_warp_9	WARPNPC,1,2

1@mcd,109,219,5	script	Main Computer#side_quest	CLEAR_NPC,{
	.@step_cd = checkquest(13188,PLAYTIME);
	.@step_hunt = checkquest(13187,HUNTING);
	switch(.@step_hunt){
		case -1:
			break;
			
		case 0:
		case 1:
			mes "[ ^0000FFMain Computer^000000 ]";
			mes "In order to reduce the Main Computer load, you need to eliminate the outage control ^0000FFcontrol device^000000 or more";
			end;
			
		case 2:
			mes "[ ^0000FFMain Computer^000000 ]";
			mes "The control device has been reduced and attempts to regain control.";
			getexp 1200000,360000;
			getitem 6752,1; //Charleston Parts
			erasequest 13187;
			setquest 13188;
			end;
	}
	switch(.@step_cd){
		case -1:
			mes "[ ^0000FFMain Computer^000000 ]";
			mes "Charleston's system was overload during regular maintenance. Disconnection from it's OS failed.";
			next;
			mes "[ ^0000FFMain Computer^000000 ]";
			mes "Unauthorized access made to the system was defended, but unauthorized data interception and conflict continued, turning the Nanosteps into monsters.";
			next;
			mes "[ ^0000FFMain Computer^000000 ]";
			mes "To accelerate the main computer's processing rate and reclaim the factory, ^ff000050 Steps^000000 must be disposed.";
			next;
			if(select("Preform the request.:Quit") == 2) end;
			mes "[ ^0000FFMain Computer^000000 ]";
			mes "Requires ^ff000050 Steps^000000 to be disposed.";
			setquest 13187;
			end;
		
		case 0:
		case 1:
			mes "[ ^0000FFMain Computer^000000 ]";
			mes "Continuous processing control devices.";
			close;
			
		case 2:
			mes "[ ^0000FFMain Computer^000000 ]";
			mes "Check the No. 2 machine, found that some of the data is damaged, try to lift the connection failed.";
			next;
			mes "[ ^0000FFMain Computer^000000 ]";
			mes "During the connection process, affected by the unknown operation, the control device all out of control.";
			next;
			mes "[ ^0000FFMain Computer^000000 ]";
			mes "In order to reduce the Main Computer load, you need to eliminate the outage control ^0000FFcontrol device^000000 or more.";
			next;
			if(select("Help deal with.:Cancel") == 2) end;
			mes "[ ^0000FFMain Computer^000000 ]";
			mes "Please destroy 20 control devices.";
			erasequest 13188;
			setquest 13187;
			end;
	}		
}

1@mcd,77,167,5	script	Shalosh#exit	4_F_SHALOSH,{
	cutin "shaloshi01.bmp",2;
	mes "[ ^0000FFShalosh^000000 ]";
	mes "......";
	next;
	switch(select("Talk.","I need help.","I want to return.")){
		case 1:
			mes "[ ^0000FFShalosh^000000 ]";
			mes "Ferre came with me, but I haven't seen him. No, thanks; I know he'll come back to me.";
			close3;
			
		case 2:
			mes "[ ^0000FFShalosh^000000 ]";
			mes "I only invited NewOZ. Well, I guess I shouldn't have opened the door for the robot who needed closure.";
			next;
			mes "[ ^0000FFShalosh^000000 ]";
			mes "You can try, but you can't change anything. How futile it is!";
			close3;
			
		case 3:
			if('cc_progress > 10){
				mes "[ ^0000FFShalosh^000000 ]";
				mes "The noise has stopped. I can send you back to where you came if you want.";
				if(select("Go back.:Stay.") == 2) end;
				getitem 6752,3;
				setquest 13186;
				erasequest 13184;
				warp "verus04",77,114;
				end;
			}
			mes "[ ^0000FFShalosh^000000 ]";
			mes "The voice of this place has not disappeared.";
			mes "What happened?";
			close3;
	}			
}

1@mcd,176,179,5	script	NewOz#extra	4_M_NEWOZ,{
	cutin "nines01.bmp",0;
	mes "[ ^0000FFNewOz^000000 ]";
	mes "After reading the letter that Charlotte wrote to me, I came to this place without knowing it. Since you are here, write a song and go back.";
	close3;
}

1@mcd,114,82,4	script	Igu#extra	4_F_IU,{
	cutin "igu04.bmp",2;
	mes "[ ^0000FFIgu^000000 ]";
	mes "Are you enjoying the adventure? There are a lot of machines here. In fact, it used to be a library in the past. Did you see those books?";
	close3;
}