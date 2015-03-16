int ADCModules = 4;
int TDCModules = 6;
int NumberOfMMM = 4;

double pi=3.14159265359;

int MMMADCChannelLimits[4][4] = {{0, 15, 80, 87},{0+16, 15+16, 80+8, 87+8},{0+32, 15+32, 80+16, 87+16},{0+48, 15+48, 80+24, 87+24}};
//int MMMTDCChannelLimits[4][4] = {{0, 15, 80, 87},{0+16, 15+16, 80+8, 87+8},{0+32, 15+32, 80+16, 87+16},{0+48, 15+48, 80+24, 87+24}};
int MMMTDCChannelLimits[4][4] = {{816, 831, 80, 87},{816+16, 831+16, 80+8, 87+8},{816+32, 831+32, 80+16, 87+16},{816+48, 831+48, 80+24, 87+24}};

//int HagarADCChannels[7] = {128+9,129+9,130+9,131+9,132+9,133+9,134+9};
int HagarADCChannels[7] = {95+25,95+26,95+27,95+28,95+29,95+30,95+31};
int HagarTDCChannels[7] = {656,657,658,659,660,661,662};
double HagarGain[7]   = {0.00461,0.00555,0.00342,0.00529,0.00453,0.00573,0.00633};
double HagarOffset[7] = {-2.8247,-2.9538,-2.7439,-3.1096,-3.5149,-2.5631,-2.8721};
double HagarPedestal[7] = {50,50,200,50,50,50,50};


//   This is how ADC limits look like effectively
//   //   
//   MMMADCChannelLimits[0][0] = 0;//First channel of the front of the first detector
//   MMMADCChannelLimits[0][1] = 15;//Last channel of the front of the first detector
//   MMMADCChannelLimits[0][2] = 80;//First channel of the back of the first detector
//   MMMADCChannelLimits[0][3] = 87;//Last channel of the back of the first detector
//   //   
//   MMMADCChannelLimits[1][0] = 16;
//   MMMADCChannelLimits[1][1] = 31;
//   MMMADCChannelLimits[1][2] = 88;
//   MMMADCChannelLimits[1][3] = 95;
//   //   
//   MMMADCChannelLimits[2][0] = 32;
//   MMMADCChannelLimits[2][1] = 47;
//   MMMADCChannelLimits[2][2] = 96;
//   MMMADCChannelLimits[2][3] = 103;
//   //   
//   MMMADCChannelLimits[3][0] = 48;
//   MMMADCChannelLimits[3][1] = 63;
//   MMMADCChannelLimits[3][2] = 104;
//   MMMADCChannelLimits[3][3] = 111;


int PulseLimits[2] = {1800, 2400};

double silicon_offset[128] =  {-168.968,-198.772,-174.247,-175.797,-156.718,-154.954,-200.519,-139.549,-198.366,-186.822,-194.288,-164.339,-168.337,-65.0572,-160.387,-86.0515,-185.858,-181.172,-213.626,-145.767,-187.324,-120.286,-196.958,-164.833,-231.898,-219.998,-234.078,-234.137,-196.327,-168.337,-137.259,-117.097,-104.795,-93.3315,-130.7,-95.7034,-143.824,-93.2749,-245.378,-61.288,-66.8823,-118.128,-130.505,-113.8,-195.205,-98.6295,-164.514,-113.121,-339.523,-292.835,-202.872,-254.645,-226.726,-241.886,-282.45,-251.477,-262.653,-303.501,-230.4,-289.334,-216.94,-163.518,-242.933,-134.158,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-135.655,-119.103,-49.8171,-75.5737,-131.49,-89.9631,-93.7386,-153.239,-61.288,-93.5364,-128.258,-100.068,-160.454,-115.918,-77.7873,-104.844,-30.1605,-37.7949,-83.0038,-105.674,-67.8342,-10.5308,-51.308,-71.2376,-91.0828,-26.77,-49.271,-81.6858,-68.4558,-121.084,-20.2022,-45.4696,0,0,0,0,0,0,0,0,0.,0,0,0,0,0,0,0};
//{-167.805,-214.406,-187.454,-181.633,-160.386,-149.132,-202.629,-160.261,-203.654,-173.817,-187.64,-157.683,-148.687,-92.1872,-161.218,-70.8537,-180.455,-180.758,-227.364,-152.841,-184.163,-138.119,-178.638,-167.513,-235.224,-225.14,-196.467,-234.196,-171.881,-185.131,-151.409,-145.787,258.692,-88.8767,-140.271,-101.703,-140.5,-88.484,-245.035,-77.4569,-94.7413,-146.396,-136.314,-117.08,-215.074,-105.078,-144.869,-161.288,-295.513,-297.778,-193.066,-238.863,-246.341,-266.892,-275.673,-259.938,-264.263,-320.586,-240.4,-273.869,-234.21,-175.276,-229.119,-100.009,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-153.9,-141.116,-66.7166,-103.2,-130.332,-95.8439,-112.015,-162.337,-85.2311,-104.158,-133.836,-104.588,-176.148,-125.141,-90.5022,-124.296,-29.529,-61.7865,-88.3409,-114.406,-92.1489,-5.52266,-50.7833,-84.6803,-97.1285,-49.1359,-65.4897,-101.801,-92.5068,-116.007,-49.3386,-73.9171,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
 
double silicon_gain[128] = {2.72838,2.71065,2.72963,2.71972,2.73757,2.68715,2.73757,2.77656,2.79437,2.75694,2.82431,2.66121,2.87868,2.94297,2.78608,2.74183,2.80399,2.86851,2.83897,2.73757,2.83367,2.86309,2.88007,2.79437,2.82959,2.88007,2.85895,2.77528,2.89454,2.87868,2.93237,2.88338,2.88007,2.85354,2.89919,2.90011,2.88891,2.88007,2.91049,2.93094,2.93237,2.86903,2.90011,2.93237,2.94735,2.95364,2.98062,2.97474,3.19187,3.19866,3.14867,3.19755,3.11697,3.13651,3.17261,3.11802,3.07051,3.16596,3.23089,3.23795,3.24914,3.1609,3.24914,3.23682,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3.0147,2.89919,3.03056,2.98564,3.00207,3.03668,3.0132,2.98513,2.93094,2.98513,3.0244,3.01932,3.01932,3.02538,3.0657,2.95221,2.87868,2.86903,2.94155,2.91049,2.99612,2.92094,2.83367,2.94155,2.96391,2.87321,2.86903,3.0132,2.8903,2.82298,2.93144,2.74682,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
//{2.7211,2.71494,2.73297,2.73106,2.73573,2.68548,2.76225,2.80152,2.79172,2.75188,2.80635,2.66006,2.75826,2.96099,2.78068,2.73402,2.79736,2.86712,2.84351,2.74067,2.83164,2.86948,2.87157,2.79478,2.83121,2.88493,2.84582,2.77553,2.88338,2.88706,2.93624,2.89496,2.74762,2.8514,2.89757,2.89894,2.88723,2.87429,2.90762,2.93522,2.94179,2.87595,2.90036,2.93048,2.95111,2.95414,2.97117,2.99479,3.17541,3.19887,3.14558,3.18869,3.12393,3.14539,3.17036,3.12102,3.07041,3.17293,3.2341,3.23097,3.25645,3.16729,3.24288,3.06999,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3.01396,2.90243,3.03025,2.99131,2.99434,3.03356,3.01627,2.97887,2.93761,2.98534,3.02228,3.01619,3.02228,3.0249,3.06732,2.95583,2.87665,2.86676,2.94053,2.91049,2.99978,2.91588,2.82934,2.94514,2.96318,2.88167,2.87429,3.01928,2.89797,2.81918,2.94514,2.75654,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
