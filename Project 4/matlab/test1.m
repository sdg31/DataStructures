clc;
clear all;
close all;

xs = 10:10:50;
xm = 10:10:70;
xl = 10:10:90;

%-------------- 101 items -----------------

% collisons from 10% - 90% full, 101 items
tc101 = [1 4 15 20 28];
q101 = [2 4 13 19 29];
d101 = [1 4 9 11 15];

figure(1);
subplot(3,1,1);
plot(xs, tc101, xs, q101, xs, d101);
title('Inserting into 101 sized table');
legend('two-choice hashing', 'quadratic probing', 'double hashing');
xlabel('percentage load');
ylabel('Number of Collisions');

% collisons from 10% - 90% full, 101 items
tc101 = [1 4 15 20 28 39 138];
q101 = [2 4 13 19 29 40 58];
d101 = [1 4 9 11 15 30 54];

subplot(3,1,2);
plot(xm, tc101, xm, q101, xm, d101);
title('Inserting into 101 sized table');
legend('two-choice hashing', 'quadratic probing', 'double hashing');
xlabel('percentage load');
ylabel('Number of Collisions');

% collisons from 10% - 90% full, 101 items
tc101 = [1 4 15 20 28 39 138 311 545 ];
q101 = [2 4 13 19 29 40 58 94 149 ];
d101 = [1 4 9 11 15 30 54 79 121 ];

subplot(3,1,3);
plot(xl, tc101, xl, q101, xl, d101);
title('Inserting into 101 sized table');
legend('two-choice hashing', 'quadratic probing', 'double hashing');
xlabel('percentage load');
ylabel('Number of Collisions');

%-------------- 1009 items -----------------

% collisons from 10% - 90% full, 1009 items
tc1009 = [1 9 55 116 214];
q1009 = [12 49 109 195 339];
d1009 = [6 24 57 98 181];

figure(2);
subplot(3,1,1);
plot(xs, tc1009, xs, q1009, xs, d1009);
title('Inserting into 1009 sized table');
legend('two-choice hashing', 'quadratic probing', 'double hashing');
xlabel('percentage load');
ylabel('Number of Collisions');

% collisons from 10% - 90% full, 1009 items
tc1009 = [1 9 55 116 214 451 1015];
q1009 = [12 49 109 195 339 555 818];
d1009 = [6 24 57 98 181 324 485];

subplot(3,1,2);
plot(xm, tc1009, xm, q1009, xm, d1009);
title('Inserting into 1009 sized table');
legend('two-choice hashing', 'quadratic probing', 'double hashing');
xlabel('percentage load');
ylabel('Number of Collisions');

% collisons from 10% - 90% full, 1009 items
tc1009 = [1 9 55 116 214 451 1015 8310 26884 ];
q1009 = [12 49 109 195 339 555 818 1215 1972 ];
d1009 = [6 24 57 98 181 324 485 841 1446 ];

subplot(3,1,3);
plot(xl, tc1009, xl, q1009, xl, d1009);
title('Inserting into 1009 sized table');
legend('two-choice hashing', 'quadratic probing', 'double hashing');
xlabel('percentage load');
ylabel('Number of Collisions');

%-------------- 10007 items -----------------

% collisons from 10% - 90% full, 10007 items
tc10007 = [26 166 463 1030 2050];
q10007 = [99 444 1058 1984 3294];
d10007 = [48 230 559 1091 1850];

figure(3);
subplot(3,1,1);
plot(xs, tc10007, xs, q10007, xs, d10007);
title('Inserting into 10007 sized table');
legend('two-choice hashing', 'quadratic probing', 'double hashing');
xlabel('percentage load');
ylabel('Number of Collisions');

% collisons from 10% - 90% full, 10007 items
tc10007 = [26 166 463 1030 2050 3953 9990];
q10007 = [99 444 1058 1984 3294 5276 8160];
d10007 = [48 230 559 1091 1850 3105 4947];

subplot(3,1,2);
plot(xm, tc10007, xm, q10007, xm, d10007);
title('Inserting into 10007 sized table');
legend('two-choice hashing', 'quadratic probing', 'double hashing');
xlabel('percentage load');
ylabel('Number of Collisions');

% collisons from 10% - 90% full, 10007 items
tc10007 = [26 166 463 1030 2050 3953 9990 69710 1754230 ];
q10007 = [99 444 1058 1984 3294 5276 8160 12724 21017 ];
d10007 = [48 230 559 1091 1850 3105 4947 7925 13956 ];

subplot(3,1,3);
plot(xl, tc10007, xl, q10007, xl, d10007);
title('Inserting into 10007 sized table');
legend('two-choice hashing', 'quadratic probing', 'double hashing');
xlabel('percentage load');
ylabel('Number of Collisions');

%-------------- 100003 items -----------------

% collisons from 10% - 90% full, 100003 items
tc100003 = [290 1636 4470 9821 19550];
q100003 = [1129 4485 10463 19937 33786];
d100003 = [589 2446 5964 12163 21995];

figure(4);
subplot(3,1,1);
plot(xs, tc100003, xs, q100003, xs, d100003);
title('Inserting into 100003 sized table');
legend('two-choice hashing', 'quadratic probing', 'double hashing');
xlabel('percentage load');
ylabel('Number of Collisions');

% collisons from 10% - 90% full, 100003 items
tc100003 = [290 1636 4470 9821 19550 37501 82456];
q100003 = [1129 4485 10463 19937 33786 53247 81429];
d100003 = [589 2446 5964 12163 21995 37280 60664];

subplot(3,1,2);
plot(xm, tc100003, xm, q100003, xm, d100003);
title('Inserting into 100003 sized table');
legend('two-choice hashing', 'quadratic probing', 'double hashing');
xlabel('percentage load');
ylabel('Number of Collisions');

% collisons from 10% - 90% full, 100003 items
tc100003 = [290 1636 4470 9821 19550 37501 82456 397675 135282256 ];
q100003 = [1129 4485 10463 19937 33786 53247 81429 124471 201311 ];
d100003 = [589 2446 5964 12163 21995 37280 60664 97671 166110 ];

subplot(3,1,3);
plot(xl, tc100003, xl, q100003, xl, d100003);
title('Inserting into 100003 sized table');
legend('two-choice hashing', 'quadratic probing', 'double hashing');
xlabel('percentage load');
ylabel('Number of Collisions');

%-------------- 1000003 items -----------------

% collisons from 10% - 90% full, 1000003 items
tc1000003 = [2739 15927 45059 98085 192787];
q1000003 = [10460 44423 105989 200926 339442];
d1000003 = [8375 41673 100894 190763 319012];

figure(5);
subplot(3,1,1);
plot(xs, tc1000003, xs, q1000003, xs, d1000003);
title('Inserting into 1000003 sized table');
legend('two-choice hashing', 'quadratic probing', 'double hashing');
xlabel('percentage load');
ylabel('Number of Collisions');

% collisons from 10% - 90% full, 1000003 items
tc1000003 = [2739 15927 45059 98085 192787 377551 851509];
q1000003 = [10460 44423 105989 200926 339442 535569 818338];
d1000003 = [8375 41673 100894 190763 319012 501267 757142];

subplot(3,1,2);
plot(xm, tc1000003, xm, q1000003, xm, d1000003);
title('Inserting into 1000003 sized table');
legend('two-choice hashing', 'quadratic probing', 'double hashing');
xlabel('percentage load');
ylabel('Number of Collisions');

% collisons from 10% - 90% full, 1000003 items
tc1000003 = [2739 15927 45059 98085 192787 377551 851509 5770441 1451863544 ];
q1000003 = [10460 44423 105989 200926 339442 535569 818338 1247082 2020309 ];
d1000003 = [8375 41673 100894 190763 319012 501267 757142 1140223 1819913 ];

subplot(3,1,3);
plot(xl, tc1000003, xl, q1000003, xl, d1000003);
title('Inserting into 1000003 sized table');
legend('two-choice hashing', 'quadratic probing', 'double hashing');
xlabel('percentage load');
ylabel('Number of Collisions');