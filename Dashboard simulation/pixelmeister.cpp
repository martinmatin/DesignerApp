
//// INIT ////

utft.setColor(0,0,0);
utft.fillScr(0,0,0);
//ERT
utext.setFont(Dialog18a);
utext.setForeground(200,200,200);
utext.print(28,448,"ECAM RACING TEAM");




//////////////// WIDGET BINAIRE ///////////////////

////  Variables entrées 

	int var_bin[][] = {
	  //xPos, 	yPos, xL,		yL,		colorR1,	colorG1,	colorB1,	colorR2,	colorG2,	colorB2,	warningState
	  
	
		{133,		160,	170,	80,		0,			200,			0,		255,		0,			0,			0},  // OIL PRES
		{57*(0+1),40,	100,	60,		80,			80,				80,		0,			0,			160,		1},  // PHARE
		{57*(2+1),40,	100,	60,		80,			80,				80,		0,			0,			160,		0},  // RAMPE
		{57*(4+1),40,	100,	60,		80,			80,				80,		0,			0,			160,		0},  // Cligno G
		{57*(6+1),40,	100,	60,		80,			80,				80,		253,		153,		51,			1},  // Warning
		{57*(8+1),40,	100,	60,		80,			80,				80,		0,			0,			160,		0},  // Cligno D
		{57*(10+1),40,	100,	60,		80,			80,				80,		153,		0,			153,		1},  // GPS
		{}
		};
	
	String values_bin[] = {
	
		"OIL PRES",
		"LIGHTS",
		"BAR",
		"L FL.",
		"WARN.",
		"R FL.",
		"GPS"
		
		};

// Classe
	
	for (int i=0; i <= 6 ; i++){
	
	//--> Données du widget
		// Nom et valeurs random

			String value = values_bin[i];
		
		// Centre
			int xPos =var_bin[i][0];
			int yPos = var_bin[i][1];
		
		//Taille
			int xL = var_bin[i][2];
			int yL = var_bin[i][3];
		
		
		// Couleurs
			int colorR1 = var_bin[i][4], colorG1 = var_bin[i][5], colorB1 = var_bin[i][6];
			int colorR2 = var_bin[i][7], colorG2 = var_bin[i][8], colorB2 = var_bin[i][9];
			
		
		//Etatt warning
			int warning = var_bin[i][10]; // 
	//--> Dessins
	
		
		// - Rectangle
		
		//Rectangle extérieur
			int xRect1 = xPos - (xL/2);
			int xRect2 = xPos + (xL/2);
			int yRect1 = yPos - (yL/2);
			int yRect2 = yPos + (yL/2);
			
			if (warning == 0){
				// fond noir
				utft.setColor(0,0,0);
				utft.fillRect(xRect1,yRect1,xRect2,yRect2);
				// cadre coloré
				utft.setColor(colorR1,colorG1,colorB1);
				utft.drawRect(xRect1,yRect1,xRect2,yRect2);
				// couleur du txt
				utext.setBackground(0,0,0);
				utext.setForeground(colorR1,colorG1,colorB1);
									
				}
			
			if (warning == 1){
				// fond noir
				utft.setColor(colorR2,colorG2,colorB2);
				utft.fillRect(xRect1,yRect1,xRect2,yRect2);

				// couleur du txt
				utext.setBackground(colorR2,colorG2,colorB2);
				utext.setForeground(255,255,255);
									
				}

		

				
		//Nom du widget
		byte xFontSize=14;
		byte yFontSize=18;
		
			
		int yTxtPos = yPos - (yFontSize/2);
		int xTxtPos = xPos - ((value.length()*xFontSize)/2);
		utext.setFont(Dialog18a);
		
		utext.print(xTxtPos,yTxtPos,value);

}

//////////////// WIDGET NUMERIQUES ///////////////////

////  Variables entrées 

	int var[][] = {
	  //xPos, 	yPos, xL,		yL,		txtSize	colorR,	colorG,	colorB,	warningState
	  
	
		{266+133,	160,	170,	80,		2,			255,		255,		0,			0},  // RPM
		{532+133,	160,	170,	80,		2,			204,		0,			102,		0},  // FUEL
		
		{133,		300,	170,	80,		2,			255,		255,		0,			2},  // TEMP
		{266+133,	300,	170,	80,		2,			255,		255,		0,			0},  // SPEED
		{532+133,	300,	170,	80,		2,			204,		0,			102,		0},  // BATTERY
		
		{57*(12+1),40,	100,	60,		1,			150,		120,		250,		0},  // REC
		//TIME
		{133,		425,	250,	90,		2,			150,		120,		250,		0},  // TIME
		//{266+133,	425,	250,	90,		2,			150,		120,		250,		0},  // LAP TIME
		{532+133,	425,	250,	90,		2,			150,		120,		250,		0},  // RUNNING TIME
		{}
		};
	
	String values[][] = {
	
		{"RPM","3960"},
		{"FUEL","17"},
		{"TEMP","130"},
		{"SPEED","132"},
		{"BATTERY","12"},
		{"REC","2"},
		//TIME
		{"HOUR","13:02"},
		//{"LAP TIME","03:54"},
		{"RUNING TIME","01:45"},
		{}
		};

// Classe
	
	for (int i=0; i <= 7 ; i++){
	
	//--> Données du widget
		// Nom et valeurs random
			String name =values[i][0];
			String value = values[i][1];
		
		// Centre
			int xPos =var[i][0];
			int yPos = var[i][1];
		
		//Taille
			int xL = var[i][2];
			int yL = var[i][3];
		
		/// taille écriture valeur (1/2/3)
			int txtSize = var[i][4];
		
		// Couleurs
			int colorR = var[i][5], colorG = var[i][6], colorB = var[i][7];
		
		//Etatt warning
			int warning = var[i][8]; // 0 = ok, 1= état moyen, 2=état grave
	
	//--> Dessins
	
		
		// - Rectangle
		
		//Rectangle extérieur
			int xRect1 = xPos - (xL/2);
			int xRect2 = xPos + (xL/2);
			int yRect1 = yPos - (yL/2);
			int yRect2 = yPos + (yL/2);
	
			utft.setColor(colorR,colorG,colorB);
			utft.drawRect(xRect1,yRect1,xRect2,yRect2);
			utft.setColor(0,0,0);
			utft.drawLine(xRect1+20,yRect1,xRect2-20,yRect1);
		
		//Nom du widget
			int lenName = name.length();
			int xFontPos = (xPos - ((name.length()*15)/2)); //15=xFontSize de l'écriture
				utext.setFont(Dialog18a);
				utext.setBackground(0,0,0);
				utext.setForeground(255,255,255);
				utext.print(xFontPos,yRect1,name);
				
		//Valeur du widget
		byte xFontSize=0;
		byte yFontSize=0;
			if (txtSize==1){
				utext.setFont(Dialog18a);
				xFontSize = 13;
				yFontSize = 18;
			}
				
			else if (txtSize==2){
				utext.setFont(Dialog26a);
				xFontSize = 19;
				yFontSize = 26;
			}
			else if (txtSize==3){
				utext.setFont(Dialog36a);
				xFontSize = 27;
				yFontSize = 37;
			}
			
//			utext.setBackground(0,0,0);
			utext.setForeground(255,255,255);
		
			int yTxtPos = yPos - (yFontSize/2) + 9;
			int xTxtPos = xPos - ((value.length()*xFontSize)/2);
			utext.print(xTxtPos,yTxtPos,value);
		
		//Warning
			if (warning == 0){
				utft.setColor(0,0,0);
				}
			else if (warning == 1){
				utft.setColor(255,153,51);
				}
			else if (warning == 2) {
				utft.setColor(255,0,0);
				}
			
			utft.fillRect(xRect1,yRect1,xRect2+1,yRect1-15);
}
