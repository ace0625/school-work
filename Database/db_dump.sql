--
-- PostgreSQL database dump
--

SET statement_timeout = 0;
SET client_encoding = 'SQL_ASCII';
SET standard_conforming_strings = on;
SET check_function_bodies = false;
SET client_min_messages = warning;

--
-- Name: sailors; Type: SCHEMA; Schema: -; Owner: -
--

CREATE SCHEMA sailors;


--
-- Name: spy; Type: SCHEMA; Schema: -; Owner: -
--

CREATE SCHEMA spy;


--
-- Name: store; Type: SCHEMA; Schema: -; Owner: -
--

CREATE SCHEMA store;


SET search_path = sailors, pg_catalog;

SET default_tablespace = '';

SET default_with_oids = false;

--
-- Name: boats; Type: TABLE; Schema: sailors; Owner: -; Tablespace: 
--

CREATE TABLE boats (
    bid integer NOT NULL,
    bname character varying(20),
    color character varying(10)
);


--
-- Name: reserves; Type: TABLE; Schema: sailors; Owner: -; Tablespace: 
--

CREATE TABLE reserves (
    sid integer NOT NULL,
    bid integer NOT NULL,
    day date
);


--
-- Name: sailors; Type: TABLE; Schema: sailors; Owner: -; Tablespace: 
--

CREATE TABLE sailors (
    sid integer NOT NULL,
    sname character varying(20),
    rating integer,
    age real
);


SET search_path = spy, pg_catalog;

--
-- Name: affiliation; Type: TABLE; Schema: spy; Owner: -; Tablespace: 
--

CREATE TABLE affiliation (
    aff_id integer NOT NULL,
    title character varying(20),
    description character varying(50)
);


--
-- Name: affiliationrel; Type: TABLE; Schema: spy; Owner: -; Tablespace: 
--

CREATE TABLE affiliationrel (
    aff_id integer NOT NULL,
    agent_id integer NOT NULL,
    affiliation_strength character varying(10)
);


--
-- Name: agent; Type: TABLE; Schema: spy; Owner: -; Tablespace: 
--

CREATE TABLE agent (
    agent_id integer NOT NULL,
    first character varying(20),
    middle character varying(20),
    last character varying(20),
    address character varying(50),
    city character varying(20),
    country character varying(20),
    salary integer,
    clearance_id integer
);


--
-- Name: language; Type: TABLE; Schema: spy; Owner: -; Tablespace: 
--

CREATE TABLE language (
    lang_id integer NOT NULL,
    language character varying(20)
);


--
-- Name: languagerel; Type: TABLE; Schema: spy; Owner: -; Tablespace: 
--

CREATE TABLE languagerel (
    lang_id integer NOT NULL,
    agent_id integer NOT NULL
);


--
-- Name: mission; Type: TABLE; Schema: spy; Owner: -; Tablespace: 
--

CREATE TABLE mission (
    mission_id integer NOT NULL,
    name character varying(20),
    access_id integer,
    team_id integer,
    mission_status character varying(20)
);


--
-- Name: securityclearance; Type: TABLE; Schema: spy; Owner: -; Tablespace: 
--

CREATE TABLE securityclearance (
    sc_id integer NOT NULL,
    sc_level character varying(20),
    description character varying(50)
);


--
-- Name: skill; Type: TABLE; Schema: spy; Owner: -; Tablespace: 
--

CREATE TABLE skill (
    skill_id integer NOT NULL,
    skill character varying(20)
);


--
-- Name: skillrel; Type: TABLE; Schema: spy; Owner: -; Tablespace: 
--

CREATE TABLE skillrel (
    skill_id integer NOT NULL,
    agent_id integer NOT NULL
);


--
-- Name: team; Type: TABLE; Schema: spy; Owner: -; Tablespace: 
--

CREATE TABLE team (
    team_id integer NOT NULL,
    name character varying(20),
    meeting_frequency character varying(20)
);


--
-- Name: teamrel; Type: TABLE; Schema: spy; Owner: -; Tablespace: 
--

CREATE TABLE teamrel (
    team_id integer NOT NULL,
    agent_id integer NOT NULL
);


SET search_path = store, pg_catalog;

--
-- Name: pricelist; Type: TABLE; Schema: store; Owner: -; Tablespace: 
--

CREATE TABLE pricelist (
    store character varying NOT NULL,
    beverage character varying NOT NULL,
    size integer NOT NULL,
    price money
);


SET search_path = sailors, pg_catalog;

--
-- Data for Name: boats; Type: TABLE DATA; Schema: sailors; Owner: -
--

COPY boats (bid, bname, color) FROM stdin;
101	Interlake	blue
102	Interlake	red
103	Clipper	green
104	Marine	red
105	Tubby	purple
\.


--
-- Data for Name: reserves; Type: TABLE DATA; Schema: sailors; Owner: -
--

COPY reserves (sid, bid, day) FROM stdin;
22	101	1996-10-10
22	102	1998-10-10
22	103	1998-10-08
22	104	1998-10-07
31	102	1998-11-10
31	103	1998-11-06
31	104	1998-11-12
64	101	1998-09-05
64	102	1998-09-08
74	103	1998-09-08
58	103	1996-11-12
\.


--
-- Data for Name: sailors; Type: TABLE DATA; Schema: sailors; Owner: -
--

COPY sailors (sid, sname, rating, age) FROM stdin;
22	Dustin	7	45
31	Lubber	8	55.5
58	Rusty	10	35.5
28	yuppy	9	35
44	guppy	5	35.5
29	Brutus	1	33
32	Andy	8	25.5
64	Horatio	7	35
71	Zorba	10	16
74	Horatio	9	35.5
85	Art	3	25.5
95	Bob	3	63.5
\.


SET search_path = spy, pg_catalog;

--
-- Data for Name: affiliation; Type: TABLE DATA; Schema: spy; Owner: -
--

COPY affiliation (aff_id, title, description) FROM stdin;
1	CSIS	Canadian Security Intelligence Service
2	ASIO	Australian Security Intelligence Organization
3	MI6	British Secret Service
4	KGB	Russian Secret Service
5	Mossad	Israeli Secret Service Agency
6	GSG-9	German Counterterrorism Group
7	SBC	Security Service of Ukraine
8	Interpol	International Police Organisation
9	CIA	Central Intelligence Agency
10	FBI	Federal Bureau of Intelligence
11	NSA	National Security Agency (Communications)
12	FSB	Russian Federal Security Service
13	AIVD	Dutch General Intelligence
14	MIVD	Dutch Millitary Intelligence
15	FSV	Russian Foreign Intelligence
16	MI5	British Intelligence
17	ECHELON	World Electronic Spy Network
18	BOSS	South African Special Service Agency
19	EGI	Egyptian General Intelligence
20	IGI	Iraqi General Intelligence
21	JGI	Jordanian General Intelligence
22	SGI	Syrian General Intelligence
23	Mafia	Secret terrorist group in Sicily
24	Al-Kaida	Secret islamic terrorist group
25	Hezzbollah	Secret Palestinian terrorist group
26	Redneck Knights	Secret Texas terrorist group
27	Michigan Militia	Secret society for Arms dealers
28	Hamas	Palestinian Terrorist group
29	Red Brigade	Russian Communist terrorist group
30	Columbian Cartel	Secret Columbian Narcotics Dealers
31	Hells Angels	Secret USA Motorcycle group
32	Black Panthers	Secret USA militant activist group
33	PAGAD	People against gansterism and drugs
34	IRA	Irish Republican Army
\.


--
-- Data for Name: affiliationrel; Type: TABLE DATA; Schema: spy; Owner: -
--

COPY affiliationrel (aff_id, agent_id, affiliation_strength) FROM stdin;
15	2	weak
8	3	weak
7	5	weak
23	5	medium
14	7	weak
15	7	medium
30	7	strong
16	8	weak
27	8	medium
1	14	weak
19	14	medium
2	20	weak
32	20	medium
15	24	weak
34	24	medium
19	24	strong
12	25	weak
34	30	weak
23	30	medium
28	30	strong
28	35	weak
12	35	medium
9	36	weak
21	37	weak
24	37	medium
7	37	strong
7	43	weak
4	43	medium
16	45	weak
26	48	weak
32	49	weak
15	49	medium
16	50	weak
29	50	medium
26	50	strong
26	56	weak
22	56	medium
31	58	weak
25	59	weak
24	59	medium
12	59	strong
32	61	weak
22	64	weak
32	65	weak
19	65	medium
10	69	weak
9	69	medium
2	69	strong
9	71	weak
15	71	medium
17	76	weak
30	78	weak
22	80	weak
17	80	medium
20	83	weak
13	85	weak
5	85	medium
25	86	weak
26	86	medium
14	86	strong
18	87	weak
6	88	weak
26	88	medium
34	90	weak
30	91	weak
29	91	medium
34	92	weak
11	92	medium
30	92	strong
16	93	weak
17	93	medium
19	93	strong
9	94	weak
31	94	medium
9	96	weak
20	96	medium
34	97	weak
20	97	medium
30	99	weak
13	100	weak
1	100	medium
29	100	strong
2	102	weak
26	104	weak
30	104	medium
28	104	strong
7	105	weak
27	106	weak
30	106	medium
13	106	strong
7	107	weak
21	107	medium
27	107	strong
10	108	weak
18	108	medium
19	115	weak
22	116	weak
14	116	medium
25	116	strong
22	121	weak
19	121	medium
11	122	weak
28	122	medium
15	122	strong
24	123	weak
8	123	medium
4	124	weak
1	124	medium
33	124	strong
20	125	weak
19	126	weak
20	126	medium
29	127	weak
2	128	weak
32	128	medium
12	130	weak
15	130	medium
34	130	strong
22	131	weak
30	131	medium
32	132	weak
22	133	weak
13	133	medium
19	134	weak
22	137	weak
16	138	weak
29	138	medium
8	140	weak
6	140	medium
2	140	strong
33	143	weak
5	143	medium
19	143	strong
13	144	weak
27	144	medium
22	146	weak
6	148	weak
1	148	medium
26	149	weak
15	149	medium
16	149	strong
30	150	weak
11	150	medium
19	151	weak
4	152	weak
20	153	weak
2	154	weak
25	155	weak
16	157	weak
13	159	weak
33	161	weak
8	161	medium
26	161	strong
29	163	weak
27	163	medium
21	163	strong
23	164	weak
18	165	weak
4	165	medium
13	166	weak
21	167	weak
27	168	weak
32	168	medium
5	168	strong
23	169	weak
6	169	medium
3	169	strong
12	170	weak
23	172	weak
32	172	medium
15	173	weak
31	173	medium
6	174	weak
11	174	medium
10	174	strong
12	177	weak
17	178	weak
29	178	medium
6	178	strong
15	179	weak
16	180	weak
19	180	medium
13	181	weak
15	182	weak
29	183	weak
17	183	medium
21	183	strong
10	185	weak
4	189	weak
12	189	medium
17	191	weak
7	192	weak
21	193	weak
25	198	weak
24	199	weak
18	199	medium
30	199	strong
17	201	weak
5	201	medium
7	203	weak
17	203	medium
12	203	strong
29	205	weak
22	206	weak
20	207	weak
33	207	medium
12	209	weak
20	209	medium
28	209	strong
26	210	weak
4	210	medium
2	212	weak
8	212	medium
20	217	weak
4	217	medium
5	217	strong
28	219	weak
17	219	medium
31	219	strong
21	221	weak
16	223	weak
31	226	weak
22	227	weak
31	227	medium
6	227	strong
17	229	weak
34	230	weak
4	233	weak
25	233	medium
7	236	weak
18	238	weak
12	238	medium
11	239	weak
7	240	weak
28	240	medium
23	244	weak
27	245	weak
19	245	medium
14	246	weak
15	246	medium
7	247	weak
22	247	medium
12	247	strong
19	248	weak
23	248	medium
32	248	strong
26	249	weak
11	249	medium
16	251	weak
33	251	medium
18	252	weak
9	252	medium
5	252	strong
32	257	weak
7	257	medium
25	258	weak
32	258	medium
13	260	weak
3	260	medium
18	260	strong
29	265	weak
8	265	medium
25	265	strong
25	267	weak
14	269	weak
24	269	medium
20	271	weak
34	271	medium
28	272	weak
4	275	weak
28	276	weak
9	276	medium
33	278	weak
26	278	medium
12	279	weak
28	279	medium
19	280	weak
17	280	medium
29	280	strong
32	281	weak
31	284	weak
19	288	weak
30	288	medium
14	288	strong
34	295	weak
8	297	weak
13	297	medium
17	299	weak
6	299	medium
32	299	strong
31	301	weak
8	301	medium
32	301	strong
14	303	weak
21	306	weak
20	306	medium
14	306	strong
16	307	weak
27	308	weak
11	309	weak
2	311	weak
33	313	weak
31	313	medium
14	315	weak
22	316	weak
19	319	weak
27	319	medium
1	319	strong
34	323	weak
12	323	medium
28	323	strong
5	324	weak
9	325	weak
19	326	weak
9	326	medium
3	327	weak
28	327	medium
2	327	strong
29	328	weak
8	328	medium
10	329	weak
31	332	weak
25	332	medium
23	332	strong
26	335	weak
25	336	weak
24	336	medium
22	336	strong
15	339	weak
22	342	weak
29	342	medium
23	343	weak
17	345	weak
23	345	medium
18	345	strong
22	346	weak
32	347	weak
34	347	medium
22	347	strong
3	348	weak
18	350	weak
27	350	medium
8	351	weak
26	351	medium
32	352	weak
23	352	medium
30	353	weak
6	353	medium
11	353	strong
1	354	weak
3	355	weak
25	356	weak
12	358	weak
13	358	medium
10	359	weak
23	360	weak
7	360	medium
16	360	strong
18	362	weak
1	362	medium
19	363	weak
32	364	weak
16	365	weak
4	365	medium
13	366	weak
20	367	weak
23	367	medium
27	367	strong
2	369	weak
30	369	medium
27	374	weak
13	374	medium
33	374	strong
22	377	weak
17	377	medium
10	377	strong
24	378	weak
28	378	medium
14	378	strong
12	379	weak
2	379	medium
29	380	weak
22	381	weak
3	382	weak
28	384	weak
34	384	medium
21	385	weak
1	385	medium
32	385	strong
8	386	weak
20	386	medium
29	386	strong
26	387	weak
31	387	medium
21	388	weak
13	388	medium
33	393	weak
13	393	medium
18	394	weak
12	396	weak
3	396	medium
29	396	strong
30	397	weak
22	397	medium
24	397	strong
30	398	weak
11	399	weak
22	401	weak
5	401	medium
31	401	strong
18	403	weak
21	404	weak
23	404	medium
30	405	weak
21	405	medium
27	405	strong
14	408	weak
33	408	medium
26	409	weak
1	409	medium
30	411	weak
21	411	medium
28	412	weak
4	414	weak
14	416	weak
10	416	medium
26	416	strong
8	418	weak
2	418	medium
4	418	strong
24	419	weak
32	420	weak
11	421	weak
24	421	medium
30	421	strong
22	422	weak
24	423	weak
18	425	weak
11	425	medium
5	426	weak
26	427	weak
30	428	weak
22	428	medium
28	428	strong
5	429	weak
27	429	medium
9	429	strong
2	431	weak
12	431	medium
4	436	weak
34	436	medium
17	436	strong
31	437	weak
21	438	weak
13	439	weak
18	439	medium
5	440	weak
9	442	weak
20	442	medium
11	442	strong
23	444	weak
32	444	medium
24	444	strong
10	445	weak
16	445	medium
5	445	strong
25	449	weak
5	449	medium
7	449	strong
21	450	weak
3	450	medium
23	452	weak
28	453	weak
14	453	medium
5	453	strong
15	454	weak
32	454	medium
34	455	weak
8	455	medium
30	457	weak
13	457	medium
22	459	weak
15	459	medium
13	460	weak
15	462	weak
3	462	medium
29	463	weak
34	463	medium
31	464	weak
27	466	weak
20	466	medium
24	466	strong
33	467	weak
29	467	medium
30	469	weak
16	469	medium
11	470	weak
33	474	weak
18	475	weak
21	475	medium
9	479	weak
31	482	weak
21	482	medium
34	482	strong
25	484	weak
1	484	medium
18	484	strong
33	485	weak
27	487	weak
9	487	medium
22	487	strong
1	488	weak
8	489	weak
23	489	medium
27	492	weak
34	492	medium
30	494	weak
32	494	medium
25	494	strong
32	496	weak
21	496	medium
7	496	strong
6	498	weak
8	499	weak
23	499	medium
26	502	weak
21	504	weak
22	504	medium
2	504	strong
3	505	weak
32	505	medium
16	506	weak
15	506	medium
19	506	strong
22	508	weak
21	510	weak
27	511	weak
8	511	medium
23	511	strong
14	512	weak
28	512	medium
21	513	weak
3	514	weak
26	514	medium
28	516	weak
6	516	medium
9	516	strong
27	517	weak
14	518	weak
4	518	medium
7	519	weak
29	520	weak
16	521	weak
21	522	weak
20	523	weak
3	523	medium
27	523	strong
34	524	weak
27	525	weak
2	525	medium
24	526	weak
4	526	medium
34	526	strong
5	528	weak
7	528	medium
24	530	weak
33	530	medium
5	531	weak
9	532	weak
20	533	weak
25	533	medium
32	533	strong
17	535	weak
3	536	weak
17	536	medium
11	540	weak
4	540	medium
15	541	weak
4	541	medium
20	542	weak
16	542	medium
23	542	strong
29	543	weak
13	543	medium
19	543	strong
25	544	weak
20	545	weak
23	545	medium
10	546	weak
4	547	weak
18	547	medium
27	549	weak
20	549	medium
29	551	weak
4	551	medium
7	554	weak
27	555	weak
18	555	medium
29	555	strong
32	558	weak
28	558	medium
13	560	weak
30	561	weak
32	561	medium
15	564	weak
26	564	medium
32	565	weak
23	566	weak
17	571	weak
10	571	medium
19	571	strong
11	572	weak
31	572	medium
24	577	weak
26	577	medium
34	577	strong
25	578	weak
23	579	weak
28	580	weak
13	580	medium
8	582	weak
34	583	weak
27	583	medium
23	583	strong
23	584	weak
11	586	weak
10	586	medium
17	589	weak
5	589	medium
24	591	weak
30	593	weak
15	593	medium
8	593	strong
32	595	weak
34	595	medium
5	595	strong
12	598	weak
16	598	medium
1	598	strong
33	599	weak
1	599	medium
19	599	strong
33	600	weak
7	600	medium
15	600	strong
32	602	weak
3	602	medium
19	602	strong
19	603	weak
31	603	medium
5	605	weak
23	606	weak
13	606	medium
12	606	strong
10	700	weak
20	700	medium
5	702	weak
17	703	weak
24	703	medium
1	703	strong
16	704	weak
30	704	medium
23	704	strong
21	706	weak
32	707	weak
14	708	weak
27	710	weak
22	711	weak
27	711	medium
34	712	weak
4	713	weak
32	714	weak
33	715	weak
1	716	weak
16	716	medium
10	717	weak
6	717	medium
15	717	strong
29	718	weak
11	718	medium
22	718	strong
10	720	weak
29	720	medium
18	720	strong
18	721	weak
26	721	medium
21	723	weak
17	723	medium
29	725	weak
11	725	medium
9	727	weak
1	727	medium
27	727	strong
8	728	weak
10	728	medium
22	730	weak
6	730	medium
3	732	weak
5	734	weak
27	734	medium
24	734	strong
27	735	weak
12	736	weak
13	736	medium
29	736	strong
7	737	weak
31	738	weak
30	739	weak
33	740	weak
5	740	medium
23	740	strong
12	741	weak
33	741	medium
16	741	strong
20	742	weak
29	742	medium
12	742	strong
32	743	weak
29	743	medium
3	743	strong
26	745	weak
32	745	medium
4	746	weak
17	746	medium
7	747	weak
19	747	medium
23	749	weak
7	750	weak
11	750	medium
11	751	weak
8	751	medium
7	751	strong
6	752	weak
22	752	medium
33	753	weak
16	753	medium
9	754	weak
21	754	medium
23	754	strong
31	755	weak
18	755	medium
10	755	strong
14	757	weak
27	757	medium
21	757	strong
8	759	weak
34	760	weak
20	760	medium
18	761	weak
30	761	medium
2	763	weak
23	763	medium
4	763	strong
32	764	weak
20	765	weak
26	765	medium
19	765	strong
15	766	weak
11	767	weak
6	767	medium
20	768	weak
26	769	weak
12	769	medium
5	769	strong
31	770	weak
20	770	medium
23	770	strong
32	772	weak
34	773	weak
22	776	weak
31	776	medium
5	776	strong
7	777	weak
25	777	medium
26	778	weak
7	779	weak
21	779	medium
23	779	strong
33	780	weak
25	782	weak
17	784	weak
32	784	medium
2	784	strong
9	785	weak
11	786	weak
22	787	weak
4	788	weak
31	788	medium
1	789	weak
9	789	medium
16	789	strong
7	790	weak
32	791	weak
11	791	medium
15	791	strong
33	792	weak
27	792	medium
15	793	weak
31	793	medium
16	793	strong
13	794	weak
15	795	weak
26	795	medium
29	795	strong
2	800	weak
13	800	medium
16	800	strong
17	803	weak
17	809	weak
31	812	weak
1	815	weak
3	818	weak
20	818	medium
19	818	strong
26	821	weak
20	821	medium
14	824	weak
24	824	medium
3	827	weak
17	827	medium
25	830	weak
25	833	weak
27	833	medium
4	836	weak
27	839	weak
20	839	medium
33	842	weak
10	842	medium
14	848	weak
33	851	weak
24	851	medium
26	854	weak
23	854	medium
19	854	strong
10	857	weak
3	860	weak
13	860	medium
19	863	weak
1	863	medium
16	875	weak
3	875	medium
22	881	weak
25	881	medium
28	887	weak
18	890	weak
15	893	weak
8	893	medium
28	893	strong
7	896	weak
24	896	medium
5	899	weak
33	899	medium
11	905	weak
13	905	medium
7	905	strong
6	911	weak
11	911	medium
10	911	strong
13	914	weak
2	917	weak
8	917	medium
23	917	strong
16	923	weak
32	923	medium
21	926	weak
18	929	weak
14	929	medium
11	935	weak
13	935	medium
9	938	weak
20	944	weak
32	947	weak
5	947	medium
23	947	strong
23	950	weak
32	953	weak
9	953	medium
7	956	weak
22	962	weak
17	965	weak
27	965	medium
11	965	strong
21	968	weak
24	971	weak
8	974	weak
34	974	medium
18	977	weak
8	977	medium
9	980	weak
1	980	medium
14	983	weak
13	983	medium
24	986	weak
1	986	medium
21	989	weak
29	992	weak
32	995	weak
30	995	medium
6	998	weak
12	998	medium
24	998	strong
22	1001	weak
18	1001	medium
1	1001	strong
19	1004	weak
18	1007	weak
6	1007	medium
9	1013	weak
20	1025	weak
17	1025	medium
10	1025	strong
16	1028	weak
11	1031	weak
10	1031	medium
6	1031	strong
5	1034	weak
22	1037	weak
24	1037	medium
20	1040	weak
16	1043	weak
3	1046	weak
34	1046	medium
1	1058	weak
8	1061	weak
16	1061	medium
28	1064	weak
9	1064	medium
11	1067	weak
3	1067	medium
23	1070	weak
14	1070	medium
9	1070	strong
30	1073	weak
21	1073	medium
19	1079	weak
2	1079	medium
11	1079	strong
18	1082	weak
30	1082	medium
14	1082	strong
31	1085	weak
15	1085	medium
30	1085	strong
15	1088	weak
4	1091	weak
11	1091	medium
13	1094	weak
28	1094	medium
16	1094	strong
27	1097	weak
2	1100	weak
1	1100	medium
21	1106	weak
22	1109	weak
\.


--
-- Data for Name: agent; Type: TABLE DATA; Schema: spy; Owner: -
--

COPY agent (agent_id, first, middle, last, address, city, country, salary, clearance_id) FROM stdin;
1	Nick	Jim	Black	44 1st Avenue	Athens	USA	50553	5
2	Bill	\N	Bundt	34 2nd Avenue	Paris	France	50955	6
3	Mathew	\N	Cohen	45 3rd Avenue	New York	USA	55920	5
4	Jim	\N	Cowan	1 4th Avenue	Athens	USA	66554	6
5	George	\N	Fairley	17 5th Avenue	New York	USA	76396	5
7	Bill	\N	Heeman	54 6th Avenue	San Francisco	USA	51564	4
8	Andrew	\N	James	3 7th Avenue	Paris	France	53357	3
12	Kristin	\N	Delcambre	2-6 8th Avenue	Athens	USA	50503	5
14	John	\N	Johnston	8 9th Avenue	Seattle	USA	54479	4
20	George	\N	Jones	8 10th Avenue	Paris	France	50171	6
21	Jim	\N	Kieburtz	55 11th Avenue	Baghdad	Iraq	54492	6
22	George	\N	Launchbury	44 12th Avenue	Hong Kong	China	54453	2
24	Chris	\N	Leen	7 13th Avenue	Athens	USA	56719	2
25	Jim	\N	Maier	92-94 14th Avenue	Hong Kong	China	50662	5
27	George	\N	McNamee	44 15th Avenue	Warsaw	Poland	54453	2
30	Kristin	\N	Moody	34 16th Avenue	Milan	Italy	54803	5
31	Lois	\N	Oviat	33 17th Avenue	Seattle	USA	54802	3
33	Mathew	\N	Pu	18 18th Avenue	Athens	USA	54266	3
35	Jonathan	\N	Sheard	24 19th Avenue	Warsaw	Poland	52297	2
36	Nick	\N	Steere	15 20th Avenue	San Francisco	USA	56702	5
37	John	\N	Walpole	4 21st Avenue	New York	USA	54519	6
39	Nicolas	\N	Barnard	17 22nd Avenue	Seattle	USA	55622	2
43	Jim	\N	Novick	33 23rd Avenue	Athens	USA	54803	6
45	Pete	\N	Consel	42 24th Avenue	Athens	USA	53612	5
48	Bill	\N	Bellegarde	27 25th Avenue	Seattle	USA	54512	6
49	Jonathan	\N	Hammerstrom	89 26th Avenue	Paris	France	58864	5
50	Helen	\N	Hermansky	74 27th Avenue	Athens	USA	57574	5
55	John	\N	House	35 28th Avenue	Seattle	USA	54803	5
56	Nicolas	\N	Macon	27 29th Avenue	San Francisco	USA	55261	5
58	Jason	\N	Pavel	17A 30th Avenue	Baghdad	Iraq	54264	5
59	David	\N	Shapiro	15 31st Avenue	Sydney	Austrailia	52302	6
61	Matt	\N	Song	5 32nd Avenue	Sydney	Austrailia	82018	2
62	Tim	\N	Tolmach	52 33rd Avenue	Athens	USA	55151	3
64	George	\N	van Santen	40 34th Avenue	Paris	France	55263	4
65	Jonh	\N	Wan	32 35th Avenue	San Francisco	USA	56853	6
69	Nick	\N	Yan	15 36th Avenue	Seattle	USA	56702	5
70	George	\N	Yang	12 37th Avenue	New York	USA	67392	5
71	Jim	\N	Atckinson	2 38th Avenue	Warsaw	Poland	55779	3
72	George	\N	Day	12 39th Avenue	Paris	France	54801	2
74	Tim	\N	Fisher	83 40th Avenue	Athens	USA	54547	5
76	Jonathan	\N	Gent	2 41st Avenue	Sydney	Austrailia	53153	3
78	Bill	\N	Gill	13 42nd Avenue	Baghdad	Iraq	51926	6
80	Mathew	\N	Hakanson	20 43rd Avenue	San Francisco	USA	51273	5
81	Pete	Jim	Heinlein	6 44th Avenue	Paris	France	54263	1
82	Charlene	\N	Ai	6 45th Avenue	Athens	USA	57980	5
83	Jason	\N	Amezcua	11 46th Avenue	New York	USA	51272	5
84	George	\N	Cohen	12 47th Avenue	Seattle	USA	57994	5
85	Nick	\N	Coeckx	105 48th Avenue	Warsaw	Poland	57933	5
86	Leonidas	\N	Galanis	27 49th Avenue	Baghdad	Iraq	52126	6
87	Tim	\N	Brock	45 50th Avenue	Milan	Italy	56704	6
88	David	\N	Dymock	3 51st Avenue	Hong Kong	China	50175	5
89	George	\N	Frazier	146 52nd Avenue	San Francisco	USA	58824	4
90	John	\N	Freitag	5 53rd Avenue	Paris	France	54722	5
91	Chris	\N	Glen	21 54th Avenue	Seattle	USA	55860	4
92	Nickolas	\N	Godfrey	96 55th Avenue	Baghdad	Iraq	50008	2
93	Jonathan	\N	Hoffman	1 56th Avenue	San Francisco	USA	54699	6
94	David	\N	Kadam	22 57th Avenue	San Francisco	USA	51126	3
95	Allon	\N	Kuhn	22 58th Avenue	Athens	USA	55093	4
96	Tom	\N	Lymar	12 59th Avenue	Paris	France	56485	5
97	Jason	\N	McGill	15 60th Avenue	New York	USA	90785	5
99	Charles	\N	Mou	\N	Warsaw	Poland	71207	5
100	Pete	\N	Pickering	4 61st Avenue	Los Angeles	USA	56702	5
101	Julien	\N	Sibbett	23 62nd Avenue	Bangalore	India	52152	3
102	Robert	\N	Smith	9 63rd Avenue	Seattle	USA	53922	6
104	Bill	\N	Spadaro	10 64th Avenue	Paris	France	78904	6
105	Mary	\N	Subramaniam	2 65th Avenue	Warsaw	Poland	50551	6
106	Helen	\N	Thamann	\N	San Jose	USA	71214	2
107	Socrates	\N	Yamada	2 66th Avenue	Athens	USA	57152	5
108	Michail	\N	Yu	156 67th Avenue	San Francisco	USA	56323	6
112	Natalie	\N	Zhao	30 68th Avenue	Hong Kong	China	89649	2
113	Mary	\N	Baker	7 69th Avenue	Milan	Italy	53152	2
115	George	Jim	Bahr	1 70th Avenue	Istanbul	Turkey	58075	3
116	George	\N	Berkling	3 71st Avenue	Tokyo	Japan	50885	5
121	Theo	\N	Bell	17 72nd Avenue	Seattle	USA	72541	2
122	Kristin	\N	Bull	18 73rd Avenue	Baghdad	Iraq	89364	5
123	Richard	\N	Chakpapani	37 74th Avenue	Athens	USA	56078	5
124	Michail	\N	Cushing	\N	Paris	France	71232	4
125	Bill	\N	DiLiberty	9-11 75th Avenue	New York	USA	55262	4
126	Kristin	\N	DiNucci	7 76th Avenue	Athens	USA	52252	5
127	Jason	\N	Ege	\N	San Francisco	USA	71235	4
128	Chris	\N	Eklund	19 77th Avenue	Seattle	USA	54864	5
129	Anne	\N	Elliott	45 78th Avenue	Baghdad	Iraq	50008	4
130	Nick	\N	Fessler	21 79th Avenue	Paris	France	69120	6
131	Bob	\N	Foster	12 80th Avenue	Shanghai	China	57975	5
132	Nickolas	\N	Faenov	27 81st Avenue	Baghdad	Iraq	78034	5
133	George	\N	Gerk	33 82nd Avenue	Athens	USA	57964	6
134	George	\N	Moschovitis	64 83rd Avenue	Hong Kong	China	54263	5
136	Michail	\N	Giri	24-26 84th Avenue	Baghdad	Iraq	50556	3
137	Thanassis	\N	Godbole	100 85th Avenue	Seattle	USA	51167	2
138	Pete	\N	Gupta	\N	London	England	71246	5
139	George	\N	Hakansson	73 86th Avenue	Paris	France	54154	2
140	John	\N	Hansen	\N	Hong Kong	China	71248	6
141	Nick	\N	House	34 87th Avenue	Baghdad	Iraq	58108	4
142	Nick	\N	Hunter	37 88th Avenue	San Francisco	USA	90795	5
143	Nick	\N	Jagla	11 89th Avenue	Seattle	USA	55370	6
144	Charles	\N	Larrabee	105 90th Avenue	Baghdad	Iraq	128956	5
145	Jim	\N	Platis	28 91st Avenue	Baghdad	Iraq	90674	6
146	Travis	\N	Loney	31 92nd Avenue	Warsaw	Poland	89473	3
148	George	\N	Mak	46 93rd Avenue	New York	USA	90674	3
149	Tim	\N	Miller	18 94th Avenue	Berlin	Germany	78903	3
150	John	\N	Muthusamy	23 95th Avenue	Hong Kong	China	67946	5
151	Rozalie	\N	Nadimpalli	71 96th Avenue	Rome	Greece	50172	5
152	Jason	\N	Noel	6 97th Avenue	Warsaw	Poland	72403	5
153	David	\N	Parekh	9 98th Avenue	Athens	USA	90764	6
154	Jim	\N	Pellet	7 99th Avenue	Jerusalem	Israel	96784	2
155	Pete	\N	Porter	3 100th Avenue	Seattle	USA	57484	3
157	Mary	\N	Proell	23 1st Avenue	Paris	France	54358	5
159	Charles	\N	Schaefer	30 2nd Avenue	Baghdad	Iraq	54152	5
160	George	\N	Singh	23 3rd Avenue	Tokyo	Japan	54265	3
161	Richard	\N	Staehli	18 4th Avenue	Cairo	Egypt	90673	2
163	Jim	\N	Stoltzt	13 5th Avenue	Rome	Greece	54152	5
164	Andrew	\N	Stuber	55 6th Avenue	Seattle	USA	90785	4
165	Tim	\N	Tenneti	\N	New York	USA	71273	5
166	Tom	\N	Vengataraman	34 7th Avenue	Cairo	Egypt	90867	2
167	Michail	\N	Vireday	2 8th Avenue	Baghdad	Iraq	67894	4
168	Richard	\N	Venkatesh	47-49 9th Avenue	San Francisco	USA	56592	2
169	Nick	\N	Wu	20 10th Avenue	Warsaw	Poland	89647	4
170	Theodore	Xia	Vireday	61 11th Avenue	Baghdad	Iraq	71278	5
172	Nick	\N	Avendano	29 12th Avenue	Seattle	USA	90856	2
173	Ethan	\N	Baker	7 13th Avenue	Sydney	Austrailia	98693	3
174	Travis	\N	Balasubramanian	7 14th Avenue	Toronto	Canada	67893	5
175	Luke	\N	Barklay	2 15th Avenue	Rome	Greece	54264	1
177	Chris	\N	Bedell	2 16th Avenue	Paris	France	57893	3
178	Lucie	\N	Bozack	45 17th Avenue	Sydney	Austrailia	55683	5
179	Alex	\N	Brunner	1 18th Avenue	Baghdad	Iraq	54262	1
180	Mary	\N	Chen	29 19th Avenue	Warsaw	Poland	67893	2
181	Tim	\N	Churnside	29 20th Avenue	Warsaw	Poland	72771	1
182	Ethan	Jim	Cloninger	29 21st Avenue	San Francisco	USA	89647	3
183	George	\N	DeFreez	17 22nd Avenue	Athens	USA	50552	3
184	Jim	\N	Ducosdray	12 23rd Avenue	New York	USA	78967	5
185	Josef	\N	Ellis	29 24th Avenue	Seattle	USA	90785	5
186	Bob	\N	Ferguson	\N	Baghdad	Iraq	71294	5
187	George	\N	Fossey	43 25th Avenue	Cairo	Egypt	51492	3
188	Ethan	\N	Anderson	8 26th Avenue	Warsaw	Poland	50173	2
189	Jim	\N	Ganta	\N	Paris	France	71297	4
190	Andrew	\N	Gesley	31 27th Avenue	San Francisco	USA	96300	1
191	Nickolas	\N	Huynh	149 31 28th Avenue	Warsaw	Poland	56923	4
192	Lilly	\N	Li	117 31 29th Avenue	Athens	USA	67893	3
193	Shawn	\N	Lin	51 31 30th Avenue	Maine	USA	57333	5
198	Crispin	\N	Liu	197 31 31st Avenue	Maine	USA	56703	2
199	David	\N	Lyu	83 31 32nd Avenue	Baghdad	Iraq	54672	5
200	Gregory	\N	Maker	60 31 33rd Avenue	Seattle	USA	54329	5
201	Charlene	\N	McCormick	\N	Warsaw	Poland	71309	3
202	Marie	\N	McKinney	3 31 34th Avenue	San Francisco	USA	57577	5
203	George	\N	Pardy	43 31 35th Avenue	Istanbul	Turkey	51492	3
204	Jason	\N	Pitts	2 36th Avenue	Maine	USA	89674	3
205	Ethan	\N	Plummer	6 37th Avenue	Paris	France	89674	5
206	Lucie	\N	Quintona	67 38th Avenue	Toronto	Canada	67894	6
207	Kate	\N	Rask	32 39th Avenue	Baghdad	Iraq	54482	6
209	Chris	\N	Rangarayan	5 40th Avenue	San Francisco	USA	50177	3
210	Zoe	\N	Richards	60 41st Avenue	New York	USA	53373	3
211	Marie	\N	Robinson	4 42nd Avenue	Athens	USA	78904	4
212	Tom	\N	Sathyam	30 43rd Avenue	Tokyo	Japan	90745	3
217	Jim	\N	Skinner	29 44th Avenue	Seattle	USA	78945	6
219	Valerie	\N	Sykes	3 45th Avenue	Maine	USA	77777	5
220	Andrew	\N	Tamjidi	6 46th Avenue	Hong Kong	China	50501	4
221	Ethan	\N	Viator	114 47th Avenue	Warsaw	Poland	89543	1
223	Kate	\N	Wu	7 48th Avenue	Madrid	Spain	52152	5
226	Cecile	\N	Zu	\N	Baghdad	Iraq	71334	5
227	George	\N	Barnack	15-17 49th Avenue	Toronto	Canada	54691	3
228	Pete	\N	Baron	47 50th Avenue	San Francisco	USA	89745	3
229	Jason	\N	Beeks	29 51st Avenue	Seattle	USA	54152	5
230	Travis	\N	Dye	\N	Baghdad	Iraq	71338	4
232	JING WEN	\N	Xiao Ting	\N	New York	USA	71340	5
233	Pluto	\N	Anderson	3 52nd Avenue	Athens	USA	54999	1
235	Hembert-Glen	\N	Tanner	85 53rd Avenue	Paris	France	54264	5
236	David	\N	Lewis	62 54th Avenue	Maine	USA	57375	1
237	Serguie	\N	Bikkenning	6 55th Avenue	Warsaw	Poland	67893	5
238	Sophie	\N	Dodin	17 56th Avenue	San Francisco	USA	56593	3
239	Jonathan	\N	Szilangui	24 57th Avenue	Paris	France	50393	2
240	Tim	\N	Hsu	3 58th Avenue	Seattle	USA	56151	4
243	Chris	\N	Peevy	13 59th Avenue	New York	USA	90745	2
244	Bob	\N	Sanchez	41 60th Avenue	Baghdad	Iraq	90784	5
245	Charles	\N	Sietos	37 61st Avenue	San Jose	USA	55482	1
246	Ethan	\N	Escamilla	6 62nd Avenue	Tokyo	Japan	54950	5
247	Julien	\N	Weber	42 63rd Avenue	Madrid	Spain	55262	1
248	George	\N	Kuzas	34 64th Avenue	Warsaw	Poland	56593	5
249	Aristidis	\N	Chung	17 65th Avenue	Seattle	USA	78904	3
250	Bob	\N	Mathews	37 66th Avenue	New York	USA	78904	3
251	Tom	\N	Popp	8 67th Avenue	Paris	France	57973	3
252	Ethan	\N	Petallas	85-87 68th Avenue	Athens	USA	90784	5
254	John	\N	Bailey	12 69th Avenue	San Francisco	USA	78934	3
256	Pete	\N	Ward	10 70th Avenue	Toronto	Canada	50393	4
257	Nicholas	\N	Korn	9 71st Avenue	London	England	89645	4
258	John	\N	Miller	5 72nd Avenue	Maine	USA	50555	5
260	Joanne	\N	Calderon	118 73rd Avenue	Sao Paolo	Brazil	89745	4
261	Neithan	\N	Vournas	\N	Sydney	Austrailia	71369	5
262	John	\N	Vails	20 74th Avenue	Seattle	USA	50287	4
265	Kristin	\N	Bliss	3 75th Avenue	Toronto	Canada	90745	5
266	Sunday	\N	Bazdarich	44 76th Avenue	Paris	France	78904	3
267	Irene	\N	Caster	63 77th Avenue	New York	USA	57934	3
269	Ratco	\N	Dejanocic	72 78th Avenue	Madrid	Spain	89045	2
271	Andrew	\N	Skiljan	58 79th Avenue	Athens	USA	90845	3
272	Ashvin	\N	Chung	23 80th Avenue	Tokyo	Japan	71380	5
274	Mat	\N	El Hafsi	14 81st Avenue	San Francisco	USA	57568	5
275	Zdenka	\N	Babic	6 KORDUNASKA st	Jerusalem	Israel	90784	5
276	Maric	\N	Slavco	4 82nd Avenue	Jerusalem	Israel	90748	4
277	Tim	\N	Galantine	7 83rd Avenue	Seattle	USA	89643	1
278	Nick	\N	Gerdes	16 84th Avenue	Baghdad	Iraq	89034	5
279	Jason	\N	Hanson	9 85th Avenue	Paris	France	56706	1
280	Roberto	\N	Johnson	3 86th Avenue	Warsaw	Poland	89667	5
281	Jim	\N	Khoury	19 87th Avenue	San Francisco	USA	53595	1
283	George	\N	Liao	2 88th Avenue	Toronto	Canada	50665	5
284	Charles	\N	Mayers	33 89th Avenue	Seattle	USA	90637	2
285	Crispin	\N	Montgomery	24 90th Avenue	Jerusalem	Israel	55261	2
286	Ted	\N	Rodgers	24 91st Avenue	San Francisco	USA	55461	2
287	Tamara	\N	Knuazuan	73 92nd Avenue	Tokyo	Japan	71395	5
288	Jonathan	Jim	Rolland	4 93rd Avenue	New York	USA	58094	5
293	Robert	\N	Schaible	116 94th Avenue	Paris	France	54155	5
295	Williams	\N	Schill	3 95th Avenue	Brussels	Luxembourg	58093	2
297	Goran	\N	Nincovic	18 96th Avenue	Jerusalem	Israel	89534	1
299	John	\N	Schaible	3 97th Avenue	Athens	USA	89647	3
301	George	\N	Spicer	56 98th Avenue	San Francisco	USA	89645	1
302	Michail	\N	Srinivasan	47 99th Avenue	Baghdad	Iraq	51162	2
303	Raphael	\N	Zahn	22 100th Avenue	Atlanta	USA	56923	2
306	Anri	\N	Lazaryan	34 1st Avenue	Baghdad	Iraq	89634	2
307	Tim	\N	Zhou	28 2nd Avenue	Warsaw	Poland	87633	3
308	Jim	\N	Owen	4 3rd Avenue	San Francisco	USA	58084	2
309	Jason	\N	Sabel	54 4th Avenue	Warsaw	Poland	50039	3
311	Michail	Mark	Thomson	69 55th Avenue	Athens	USA	57893	5
312	Ashvin	\N	Bolar	17 6th Avenue	Tokyo	Japan	89045	3
313	Theodore	\N	Millan	11 7th Avenue	Brussels	Luxembourg	58430	4
315	George	\N	Kottler	6 8th Avenue	San Francisco	USA	78934	2
316	Pete	\N	Hull	16 9th Avenue	Paris	France	50282	4
317	Alex	\N	Hruby	48 10th Avenue	Athens	USA	89647	3
319	Jamil	\N	Mitri	13 11th Avenue	Berlin	Germany	67894	2
320	George	\N	Williams	30 12th Avenue	New York	USA	56705	2
321	Marion	\N	Hice	23-25 13th Avenue	Athens	USA	58104	4
323	Andrew	\N	Milam	5-7 14th Avenue	San Francisco	USA	50392	5
324	Ethan	\N	Kokkelemberg	18 15th Avenue	Sydney	Austrailia	50554	1
325	Chris	\N	Cate	12 16th Avenue	Warsaw	Poland	55371	5
326	Anri	\N	Lazaryan	4 17th Avenue	Brussels	Luxembourg	78945	4
327	Elias	\N	Breitkreuz	53 18th Avenue	London	England	54794	5
328	George	W	Lush	\N	Houston	USA	220000	1
329	Julie	\N	Stamatiou	24 19th Avenue	Athens	USA	56782	2
330	Theo	\N	Carazzana	24-26 20th Avenue	Montreal	Canada	54803	2
332	George	\N	Chadwick	25-27 21st Avenue	Sao Paolo	Brazil	58094	5
335	John	\N	Peloquin	4 23rd Avenue	Warsaw	Poland	51163	1
336	Helen	\N	Ralston	\N	San Francisco	USA	71444	2
338	Nicholas	\N	Bullock	107 22nd Avenue	Paris	France	54803	2
339	Nicholas	\N	Ariss	10 23rd Avenue	Warsaw	Poland	67201	3
342	Anne	\N	Bainbridge	4 24th Avenue	Baghdad	Iraq	70372	5
343	Calin	\N	Vaduva	5 25th Avenue	Seattle	USA	92074	4
345	Jonathan	\N	Strand	39 25th Avenue	Sao Paolo	Brazil	55373	2
346	Tim	\N	Sherman	9 26th Avenue	Athens	USA	59240	1
347	Marie	\N	Heath	4 27th Avenue	Montreal	Canada	57129	1
348	Tim	\N	Odel	9 28th Avenue	Montreal	Canada	56902	1
350	Jim	\N	Booth	37 29th Avenue	San Francisco	USA	57566	4
351	Bill	\N	Fezzey	3 30th Avenue	New York	USA	50282	4
352	Bill	\N	Groty	237 31st Avenue	Athens	USA	50171	3
353	Tim	\N	McCracken	94 33th Avenue	Hong Kong	China	57482	5
354	Robert	\N	Casteel	101 34th Avenue	Seattle	USA	56864	4
355	Goran	\N	Hogan	39 35th Avenue	Bangalore	India	54802	2
356	George	\N	Shanahan	7 36th Avenue	Montreal	Canada	67893	5
358	Sockrates	\N	Jackson	7 37th Avenue	San Jose	USA	57892	5
359	Elias	\N	Escoto	1-3 38th Avenue	San Francisco	USA	61814	1
360	Antony	\N	Ledgers	161 39th Avenue	Paris	France	50924	5
361	Pete	\N	Bandelean	121 40th Avenue	Toronto	Canada	56153	5
362	Nick	\N	Fedrick	1 41st Avenue	Athens	USA	56249	3
363	Theodore	\N	Venetis	\N	Warsaw	Poland	71471	5
364	Andrew	\N	Odegard	28 42nd Avenue	Milan	Italy	56281	2
365	Mario	\N	Nwandu	67 43rd Avenue	Rome	Greece	57575	5
366	Marina	\N	Crisucci	48 44th Avenue	Berlin	Germany	50177	5
367	Charles	\N	Morris	11 45th Avenue	Rome	Greece	56875	2
369	George	\N	Gratham	3 46th Avenue	Sydney	Austrailia	56373	5
370	Natalie	\N	Lutzker	51 47th Avenue	Montreal	Canada	56875	5
373	James	\N	Gie	99 48th Avenue	Paris	France	78354	4
374	John	\N	Melms	34 49th Avenue	Athens	USA	54157	5
375	Alex	\N	Loftus	10 50th Avenue	San Francisco	USA	57320	5
377	Ti Berio Vasile	\N	Stef	130 51st Avenue	Moscow	Russia	52358	5
378	Mary	\N	Thomas	39 51st Avenue	Milan	Italy	56152	3
379	Theo	\N	Mateos	378 52nd Avenue	San Jose	USA	56875	4
380	Perry	\N	Poisson	69 53rd Avenue	Singapore	Singapore	56875	3
381	Bill	\N	Barrett	16 54th Avenue	New York	USA	55091	2
382	Jim	\N	Davis	19 55th Avenue	Warsaw	Poland	57029	4
384	Bob	\N	Nelson	7 56th Avenue	Moscow	Russia	52261	5
385	Mary	\N	Curtis	10 57th Avenue	Seattle	USA	54803	3
386	Charles	\N	Ayala	1 58th Avenue	Athens	USA	55098	2
387	Nickolas	\N	Nastos	16 59th Avenue	Paris	France	56875	1
388	Nickolas	\N	Mark	7 60th Avenue	London	England	54152	2
389	Charlene	\N	Odell	\N	Amsterdan	Holland	71497	5
391	George	\N	Riley	4 61st Avenue	Sydney	Austrailia	73922	2
393	Efi	\N	Sanchez	5 62nd Avenue	Moscow	Russia	57984	5
394	Pete	\N	Campos	3 63th Avenue	Milan	Italy	54801	1
395	Eve	\N	Barker	8 64th Avenue	Sacramento	USA	56734	3
396	Jim	\N	Frazee	3-5 65th Avenue	Athens	USA	54825	4
397	Jim	\N	Munoz	40 66th Avenue	Madrid	Spain	78643	5
398	Tim	\N	Ridway	42 67th Avenue	New York	USA	53152	2
399	Filip	\N	Labrez	11 68th Avenue	Jerusalem	Israel	54156	2
401	Valerie	\N	Wilkins	9 69th Avenue	Seattle	USA	56693	2
402	Eve	\N	Robles	9 70th Avenue	San Francisco	USA	53373	5
403	Jim	\N	Goodwin	40 71st Avenue	Paris	France	54879	2
404	Charles	Jim	Simons	24 72nd Avenue	Athens	USA	52152	4
405	Marie	\N	Angle	4 73th Avenue	Istanbul	Turkey	56730	1
407	John	\N	Roberts	34 74th Avenue	Moscow	Russia	51274	5
408	John	\N	Wood	54 75th Avenue	Tokyo	Japan	50320	2
409	Chris	\N	Cockerham	1 75th Avenue	Toronto	Canada	78403	2
410	Lilly	\N	Lee	106 76th Avenue	Jerusalem	Israel	56703	3
411	Lois	\N	Samons	15 77th Avenue	Cairo	Egypt	89564	4
412	Calin	\N	Cenan	\N	San Francisco	USA	71520	5
414	Hercules	\N	Wadell	21 78th Avenue	London	England	89043	1
415	Bill	\N	Arkinson	1 79th Avenue	Seattle	USA	56485	4
416	Nestor	\N	Zanten	64 80th Avenue	Paris	France	51167	5
417	Ethan	\N	Hackbarth	1 81st Avenue	Sydney	Austrailia	89654	4
418	Cecile	\N	Roger	17 82nd Avenue	Rome	Greece	57995	5
419	George	\N	Carter	2 83rd Avenue	London	England	89465	4
420	Ethan	\N	Grantz	25 84th Avenue	Malaga	Spain	50392	1
421	George	\N	Tuazon	868 85th Avenue	Athens	USA	54802	5
422	Mary	\N	Zhang	12 86th Avenue	San Francisco	USA	56875	2
423	Nicholas	\N	Ziemann	9 87th Avenue	Moscow	Russia	50665	2
425	Jim	\N	Peroulis	27 88th Avenue	Jerusalem	Israel	55262	5
426	Mustapha	\N	Labied	16 89th Avenue	Bangalore	India	89009	5
427	Kostas	\N	Clute	8 90th Avenue	Paris	France	50171	4
428	Valerie	\N	Bocian	2 91st Avenue	Paris	France	55502	2
429	George	\N	Carter	3 92nd Avenue	Sydney	Austrailia	56373	5
431	Travis	\N	Lee	32 93rd Avenue	New York	USA	54373	5
432	John	\N	Miller	76 94th Avenue	Baghdad	Iraq	57976	1
436	Mat	\N	Mumper	3 95th Avenue	San Francisco	USA	56152	1
437	Ethan	\N	Adkins	26 96th Avenue	Athens	USA	51166	3
438	Jim	\N	Rankin	1 97th Avenue	Paris	France	89575	4
439	Kristin	\N	Mattson	4 98th Avenue	Seattle	USA	50551	1
440	Eve	\N	Hoffman	55 99th Avenue	Cairo	Egypt	54911	1
441	Irina	\N	Malezhic	\N	Warsaw	Poland	71549	1
442	Charles	\N	Rivera	17 100th Avenue	Jerusalem	Israel	90096	4
444	Georgetta	\N	Ordean	34 1st Avenue	Paris	France	89654	5
445	Eve	\N	Bushong	5 2nd Avenue	Jerusalem	Israel	56873	2
446	Michail	\N	McGowan	7 3rd Avenue	Jerusalem	Israel	78439	5
447	George	\N	Micelbart	\N	Seattle	USA	71555	2
448	Andrew	\N	Lee	50 4th Avenue	Bangalore	India	89643	2
449	Lilly	\N	Viero	12 5th Avenue	San Francisco	USA	78543	3
450	George	\N	Tavaglione	1 6th Avenue	Baghdad	Iraq	56886	2
451	Mario	\N	Freeman	11 7th Avenue	Athens	USA	78543	5
452	Tim	\N	Starr	8 8th Avenue	Jerusalem	Israel	58430	5
453	Antony	\N	Rideout	20 25th Avenue	Jerusalem	Israel	78643	1
454	Dan	\N	Crossman	3 26th Avenue	Rome	Greece	89573	3
455	Chris	Mark	Patterson	17 27th Avenue	Malaga	Spain	54928	1
457	Alex	\N	Sage	5 28th Avenue	London	England	57973	5
458	Dennis	\N	Whelchel	4 29th Avenue	Seattle	USA	78643	1
459	Nicholas	\N	Papadakis	23 30th Avenue	Athens	USA	54802	5
460	Yong	\N	Senga	37 31st Avenue	Hong Kong	China	71568	1
461	John	\N	Anderson	2 32nd Avenue	Jerusalem	Israel	50313	5
462	George	\N	Ashmore	4 33th Avenue	Paris	France	78875	1
463	John	\N	Beals	7 34th Avenue	Baghdad	Iraq	89754	2
464	George	\N	Broadbent	16 35th Avenue	Warsaw	Poland	50319	4
465	Kristin	\N	Cruz	12 36th Avenue	Baghdad	Iraq	90854	1
466	Michail	\N	Torres	34 37th Avenue	Baghdad	Iraq	50814	4
467	Mario	\N	Fedick	23 38th Avenue	Tokyo	Japan	71575	5
469	Chris	\N	Fix	4 29th Avenue	Sydney	Austrailia	78453	5
470	Elias	\N	Gailey	5 30th Avenue	Baghdad	Iraq	90784	3
472	Michail	\N	Gelles	3 31st Avenue	Tokyo	Japan	71580	3
473	Ted	\N	Kearney	67 32nd Avenue	Warsaw	Poland	89643	4
474	George	\N	Kronenfeld	4 33th Avenue	Baghdad	Iraq	56864	5
475	George	\N	Ness	23 34th Avenue	Warsaw	Poland	89743	5
476	Tim	\N	Ness	49 35th Avenue	New York	USA	51426	5
477	Emy	\N	Andria	8 36th Avenue	San Francisco	USA	54953	2
479	Johanne	\N	Patterson	133 37th Avenue	Jerusalem	Israel	51924	1
481	Steve	\N	Taube	5 38th Avenue	Warsaw	Poland	89763	2
482	Ethan	\N	Taylor	15 39th Avenue	Warsaw	Poland	98097	1
484	Jason	\N	Velez	43 40th Avenue	Warsaw	Poland	89097	5
485	Pete	\N	Ibanez	45 41th Avenue	Baghdad	Iraq	90876	5
487	Nick	\N	Wilke	98 46th Avenue	Warsaw	Poland	50017	1
488	Bill	\N	White	3 47th Avenue	Baghdad	Iraq	90876	4
489	John	\N	Taylor	5 48th Avenue	Baghdad	Iraq	58038	3
490	Chris	\N	Selsor	6 49th Avenue	Warsaw	Poland	90879	2
491	Nicholas	\N	Gill	2 50th Avenue	Warsaw	Poland	55569	1
492	George	\N	Reed	22 51st Avenue	Warsaw	Poland	91127	2
494	George	\N	Nathanael	5 52nd Avenue	Warsaw	Poland	89643	1
496	George	\N	Cahill	7 53rd Avenue	Warsaw	Poland	90843	5
497	Chris	\N	Barth	4 54th Avenue	Baghdad	Iraq	50924	2
498	Tim	\N	Divola	7 55th Avenue	Warsaw	Poland	58937	5
499	Steve	\N	Giegerich	56 56th Avenue	Warsaw	Poland	51937	2
500	Kemal	\N	Green	23 57th Avenue	Baghdad	Iraq	58094	5
501	John	\N	Strombone	4 58th Avenue	Baghdad	Iraq	50934	3
502	Ted	\N	Suderburg	53 59th Avenue	Paris	France	58037	5
503	Rudolf	Jim	Thorpe	8 60th Avenue	Athens	USA	71611	3
504	Anne	\N	Barr	172 61st Avenue	Athens	USA	52592	2
505	Andrew	\N	Wells	52 62nd Avenue	New York	USA	54157	5
506	George	\N	Leffler	105 63rd Avenue	San Francisco	USA	54592	5
507	Dan	\N	Virata	3 64th Avenue	Seattle	USA	57374	5
508	Travis	\N	Fader	46 65th Avenue	Athens	USA	78643	4
510	Bob	\N	Save	57 66th Avenue	San Jose	USA	57975	1
511	Ted	\N	Aquino	2 67th Avenue	San Francisco	USA	54373	2
512	Chris	\N	Nyitray	89 68th Avenue	Sydney	Austrailia	54372	2
513	Steve	\N	Radeka	124 69th Avenue	Warsaw	Poland	56873	5
514	Charles	\N	Alagar	119 70th Avenue	Paris	France	78112	2
516	Mario	\N	Silverman	7 71st Avenue	Sydney	Austrailia	57983	5
517	Neithan	\N	Nieves	3 72nd Avenue	Warsaw	Poland	50311	5
518	John	\N	Lomeli	32 73rd Avenue	New York	USA	54264	3
519	Nick	\N	Sinclair	29 74th Avenue	Athens	USA	89750	2
520	Andrew	\N	Perez	2 75th Avenue	Baghdad	Iraq	67094	3
521	George	\N	Welch	4 76th Avenue	Warsaw	Poland	89637	2
522	Steve	\N	Dochtermann	3 77th Avenue	Tokyo	Japan	89745	5
523	Manuel	\N	Peterson	4 78th Avenue	Baghdad	Iraq	90854	3
524	John	\N	Bloor	5 79th Avenue	Warsaw	Poland	89643	1
525	Pete	Mark	Morrison	43 80th Avenue	Warsaw	Poland	71633	2
526	Steve	\N	Gozansky	45 81st Avenue	Tokyo	Japan	78300	3
527	Pete	\N	Dochterman	23 82nd Avenue	Paris	France	90673	5
528	Peter	\N	Love	\N	New York	USA	71636	2
529	George	\N	Scarano	26 83rd Avenue	San Francisco	USA	67734	5
530	John	\N	French	58 84th Avenue	Seattle	USA	54591	3
531	David	\N	Long	22 85th Avenue	Boston	USA	54265	1
532	Kristin	\N	Kimberly	329 86th Avenue	Athens	USA	50936	5
533	Mat	\N	Smithernan	2 87th Avenue	Cairo	Egypt	71641	3
534	Alex	\N	Doug	14 88th Avenue	Boston	USA	89641	5
535	John	\N	Masi	3 89th Avenue	Jerusalem	Israel	57484	3
536	Dan	\N	Smith	1-3 90th Avenue	New York	USA	50392	1
537	Perry	\N	Young	3 91st Avenue	San Francisco	USA	51165	5
538	Slavko	\N	Maric	3 92nd Avenue	Seattle	USA	57049	4
539	Jonathan	\N	Rinne	8 93rd Avenue	Delhi	India	56264	2
540	George	\N	Miller	86 94th Avenue	Istanbul	Turkey	56372	3
541	Jim	\N	Rife	16 87th Avenue	Sydney	Austrailia	78453	2
542	Antony	\N	Henry	\N	London	England	71650	3
543	Mario	\N	Rinne	27 88th Avenue	Cairo	Egypt	62386	1
544	Margaret	\N	Moyer	12 89th Avenue	Paris	France	57924	1
545	Nick	\N	Brewer	25 90th Avenue	Athens	USA	56884	5
546	Tim	\N	Deleeuw	23 91st Avenue	Malaga	Spain	71654	1
547	Kathrin	\N	Jenson	2 92nd Avenue	Riverside	USA	57894	5
549	Kate	\N	Clarke	13 93th Avenue	Delhi	India	54803	1
550	Bill	\N	Zahedi	\N	Athens	USA	71658	4
551	Bill	\N	Jeturian	11 94th Avenue	San Francisco	USA	54157	5
552	Chris	\N	McGee	11 95th Avenue	Seattle	USA	54265	5
554	Peter	\N	Carlos	\N	Berlin	Germany	71662	4
555	Sophie	\N	Jaros	21 96th Avenue	Paris	France	82563	1
556	George	\N	Spindler	5 97th Avenue	Delhi	India	56873	2
557	Bill	\N	Cogan	3 98th Avenue	Athens	USA	50282	4
558	Manuel	\N	Reynolds	33 99th Avenue	New York	USA	54592	5
559	Alex	\N	Richards	53 100th Avenue	San Francisco	USA	53151	2
560	George	\N	Flood	2 1st Avenue	Toronto	Canada	58130	1
561	Jason	\N	Urry	22 2nd Avenue	Athens	USA	78342	2
563	George	\N	Fast	\N	Seattle	USA	71671	2
564	Steve	\N	Vigil	56 3rd Avenue	Sao Paolo	Brazil	53594	3
565	Chris	\N	Nakayama	53 4th Avenue	Paris	France	54265	5
566	Pete	\N	Moses	67 5th Avenue	San Francisco	USA	50286	5
571	George	\N	Byus	7 6th Avenue	New York	USA	67523	4
572	Mary	\N	Debus	78 7th Avenue	Sydney	Austrailia	55591	5
574	Bill	\N	Dugaiczyk	5-7 8th Avenue	Bangalore	India	50904	5
577	Luke	\N	Dunn	\N	Seattle	USA	71685	4
578	Bill	\N	Gallie	19 9th Avenue	Madrid	Spain	50555	5
579	Steve	\N	Henry	10 10th Avenue	San Francisco	USA	53262	5
580	George	\N	Jiammin	14 11th Avenue	Athens	USA	55869	5
581	Nicholas	\N	Larsen	9 12th Avenue	Tokyo	Japan	56485	2
582	Nicholas	\N	Liou	9 13th Avenue	Toronto	Canada	56464	2
583	John	\N	Luben	\N	Sydney	Austrailia	71691	3
584	Matt	\N	Martinez	43 25th Avenue	New York	USA	71692	4
585	Jim	\N	Norman	10 26th Avenue	San Francisco	USA	50552	4
586	Kate	\N	Tenne	54 27th Avenue	Hong Kong	China	89632	4
587	Robert	\N	Roberts	\N	Seattle	USA	71695	5
588	Kristin	\N	Sindler	3 28th Avenue	Baghdad	Iraq	89112	5
589	John	\N	Traugh	25 29th Avenue	Paris	France	53701	5
591	Steve	\N	Wilkens	37 30th Avenue	Athens	USA	71699	1
593	Kathrin	\N	Redd	23 31st Avenue	San Francisco	USA	58953	2
594	Bill	Mark	Herrera	4 32nd Avenue	Seattle	USA	71702	4
595	Bob	\N	Berkowitz	29a 33rd Avenue	Boston	USA	54262	2
598	George	\N	Serewis	62-64 34th Avenue	Las Vegas	USA	53152	1
599	George	\N	Undem	4 35th Avenue	New York	USA	54155	4
600	Steve	Jim	Wong	18 36th Avenue	New York	USA	67421	3
601	Alex	\N	Acevedo	\N	Paris	France	71709	5
602	Ted	\N	Sishaw	46 37th Avenue	Athens	USA	56968	5
603	Andrew	\N	Southard	31 38th Avenue	Athens	USA	71711	5
604	Crispin	\N	Rios	96 39th Avenue	Athens	USA	89632	2
605	Lilly	\N	Lefa	24 40th Avenue	Athens	USA	50177	1
606	Traian	Mark	Icobet	\N	Paris	France	71714	5
700	Christopher	R	Boxer	112 HART	Washington DC	USA	56224	4
701	Gordon	N	Cornyn	517 HART	Washington DC	USA	259534	1
702	Richard	D	Salazar	\N	Pittsburgh	USA	173190	3
703	David	R	Carper	513 HART	Miami	USA	257526	3
704	Orrin	G	Nelson	720 HART	Pittsburgh	USA	361440	7
705	Michael	J	McCain	241 RUSSELL	Miami	USA	120982	1
706	Mary	J	Lott	487 RUSSELL	Miami	USA	244474	1
707	Daniel	R	Cantwell	717 HART	Miami	USA	359934	3
708	Robert	C	Sessions	335 RUSSELL	Pittsburgh	USA	168170	5
709	George	O	Collins	172 RUSSELL	Miami	USA	86344	4
710	Ben	T	Baucus	511 HART	Miami	USA	256522	1
711	Harry	M	Corzine	502 HART	Norfolk	USA	252004	4
712	Jeff	M	Dole	120 RUSSELL	Pittsburgh	USA	60240	7
713	Daniel	R	Byrd	311 HART	Miami	USA	156122	5
714	John	J	Hagel	248 RUSSELL	Miami	USA	124496	2
715	James	M	DeWine	140 RUSSELL	Pittsburgh	USA	70280	2
716	Thad	B	Talent	493 RUSSELL	Miami	USA	247486	1
717	Patrick	E	Pryor	257 DIRKSEN	Miami	USA	129014	5
718	Chuck	R	Brownback	303 HART	Miami	USA	152106	3
719	Mark	J	Lincoln	355 DIRKSEN	Pittsburgh	USA	178210	1
720	Michael	H	McConnell	361-A RUSSELL	Miami	USA	181222	1
721	John	J	Harkin	731 HART	Norfolk	USA	366962	5
722	Bill	T	Bayh	463 RUSSELL	Miami	USA	232426	1
723	Jim	L	Durbin	332 DIRKSEN	Miami	USA	166664	2
724	Conrad	R	Burns	187 DIRKSEN	Miami	USA	93874	1
725	Richard	D	Sarbanes	309 HART	Miami	USA	155118	3
726	Paul	E	Reid	528 HART	Miami	USA	265056	7
727	Norm	G	Murray	173 RUSSELL	Miami	USA	86846	5
728	Pete	D	Roberts	109 HART	Miami	USA	54718	1
729	Dianne	P	Chambliss	416 RUSSELL	Miami	USA	208832	2
730	Ken	J	Kennedy	317 RUSSELL	Miami	USA	159134	5
731	Johnny	J	Hatch	104 HART	Washington DC	USA	52208	2
732	Christopher	S	Bond	274 RUSSELL	Miami	USA	137548	4
733	Max	J	Lugar	306 HART	Miami	USA	153612	7
734	Blanche	T	Bennett	431 DIRKSEN	Miami	USA	216362	5
735	John	L	Enzi	379A RUSSELL	Miami	USA	190258	1
736	Saxby	C	Stabenow	522 HART	Miami	USA	262044	7
737	John	K	Grassley	135 HART	Pittsburgh	USA	67770	3
738	Larry	J	Kyl	730 HART	Pittsburgh	USA	366460	4
739	Lincoln	J	Landrieu	724 HART	Miami	USA	363448	4
740	Olympia	G	Nelson	716 HART	Miami	USA	359432	2
741	John	K	Feinstein	331 HART	Norfolk	USA	166162	2
742	Byron	S	Biden	201 RUSSELL	Miami	USA	100902	3
743	Lisa	J	Lautenberg	324 HART	Miami	USA	162648	7
744	Elizabeth	P	Coburn	\N	Pittsburgh	USA	173190	3
745	Wayne	A	Wyden	516 HART	Miami	USA	259032	7
746	Arlen	W	Akaka	141 HART	Miami	USA	70782	3
747	George	O	Conrad	530 HART	Pittsburgh	USA	266060	2
748	Mel	J	Martinez	\N	Pittsburgh	USA	173190	3
749	Tim	B	Thune	\N	Pittsburgh	USA	173190	3
750	Jon	J	Hutchison	284 RUSSELL	Miami	USA	142568	2
751	Mark	J	Lieberman	706 HART	Norfolk	USA	354412	2
752	Charles	S	Bingaman	703 HART	Miami	USA	352906	1
753	Jeff	M	Domenici	328 HART	Washington DC	USA	164656	4
754	Herb	M	Craig	520 HART	Pittsburgh	USA	261040	4
755	John	L	Feingold	506 HART	Miami	USA	254012	2
756	Trent	B	Warner	\N	Pittsburgh	USA	112950	3
757	Tom	B	Vitter	\N	Pittsburgh	USA	173190	3
758	John	L	Ensign	364 RUSSELL	Miami	USA	182728	4
759	Frank	P	Coleman	320 HART	Pittsburgh	USA	160640	2
760	Robert	C	Shelby	110 HART	Miami	USA	55220	2
761	Kent	J	Kerry	304 RUSSELL	Norfolk	USA	152608	2
762	Mike	H	Mikulski	709 HART	Miami	USA	355918	1
763	Hillary	M	Crapo	239 DIRKSEN	Miami	USA	119978	5
764	Jon	J	Inhofe	453 RUSSELL	Miami	USA	227406	3
765	Edward	P	Clinton	476 RUSSELL	Miami	USA	238952	2
766	Lamar	J	Kohl	330 HART	Pittsburgh	USA	165660	7
767	Ron	C	Smith	404 RUSSELL	Miami	USA	202808	2
768	Russell	C	Snowe	154 RUSSELL	Miami	USA	77308	4
769	Craig	R	Burr	\N	Pittsburgh	USA	173190	3
770	Susan	B	Sununu	111 RUSSELL	Miami	USA	55722	3
771	Thomas	B	Thomas	307 DIRKSEN	Washington DC	USA	154114	2
772	Joseph	J	Inouye	722 HART	Miami	USA	362444	2
773	Evan	P	Cochran	113 DIRKSEN	Miami	USA	56726	5
774	Tom	B	Voinovich	317 HART	Miami	USA	159134	5
775	Richard	D	Santorum	511 DIRKSEN	Miami	USA	256522	1
776	Barack	T	Alexander	302 HART	Miami	USA	151604	2
777	Rick	C	Schumer	313 HART	Miami	USA	157126	1
778	Joseph	J	Isakson	\N	Pittsburgh	USA	173190	3
779	Pat	F	Obama	\N	Pittsburgh	USA	173190	3
780	James	M	DeMint	\N	Pittsburgh	USA	173190	3
781	James	M	Dodd	448 RUSSELL	Washington DC	USA	224896	2
782	John	K	Gregg	393 RUSSELL	Miami	USA	197286	3
783	Barbara	T	Allard	525 DIRKSEN	Pittsburgh	USA	263550	3
784	Maria	J	Leahy	269 RUSSELL	Miami	USA	135038	5
785	Chuck	R	Bunning	316 HART	Miami	USA	158632	4
786	Sam	C	Specter	711 HART	Miami	USA	356922	3
787	Richard	D	Rockefeller	531 HART	Miami	USA	266562	3
788	Barbara	T	Allen	204 RUSSELL	Miami	USA	102408	7
789	Mitch	H	Murkowski	709 HART	Miami	USA	355918	1
790	Jack	M	Dayton	346 RUSSELL	Miami	USA	173692	4
791	Judd	J	Jeffords	413 DIRKSEN	Washington DC	USA	207326	2
792	Kay	J	Johnson	136 HART	Miami	USA	68272	4
793	Jim	M	Dorgan	713 HART	Miami	USA	357926	5
794	Debbie	R	Chafee	141A RUSSELL	Miami	USA	70782	3
795	Patty	E	Reed	728 HART	Miami	USA	365456	2
800	John	T	Oates	10 70th Suerette Avenue	Paris	France	57893	3
803	Nickolas	R	Baylor	114 Basque Avenue	Mosul	Iraq	71334	4
806	Nick	P	Lopez	116 94th Avenue	Warsaw	Poland	72771	4
809	Charles	M	Freed	117 31 29th Avenue	Paris	France	51162	1
812	Kate	M	Hall	118 73rd Avenue	Hong Kong	China	90748	5
815	Ethan	J	Watt	12 23rd Avenue	Athens	USA	78945	5
818	Travis	H	Drabowsky	12 69th Avenue	Krakow	Poland	71294	4
821	Marie	D	Richert	13 59th Avenue	Toronto	Canada	90745	5
824	Andrew	R	Floyd	14 81st Avenue	Baghdad	Iraq	71297	4
827	George	R	Leonhard	149 31 28th Avenue	Cairo	Egypt	57973	3
830	Nicholas	M	Beene	15-17 49th Avenue	Istanbul	Turkey	77777	4
833	Michail	J	Andrews	16 84th Avenue	Madrid	Spain	54155	2
836	Zoe	J	Petrocelli	17 22nd Avenue	New York	USA	56593	3
839	Zdenka	J	Smith	17 56th Avenue	San Francisco	USA	90784	5
842	Irene	J	Yastrzemski	17 65th Avenue	Seattle	USA	56592	3
845	Julien	J	Conigliaro	19 87th Avenue	Baghdad	Iraq	51492	1
848	Charles	J	Scott	197 31 31st Avenue	Rome	Greece	54999	2
851	David	J	Conigliaro	2 16th Avenue	Seattle	USA	90745	5
854	Jim	J	Moses	2 36th Avenue	Baghdad	Iraq	98693	6
857	George	J	Alvarado	2 88th Avenue	Baghdad	Iraq	89745	5
860	Michail	H	Satriano	2 8th Avenue	Baghdad	Iraq	71278	4
863	Lilly	F	Schofield	20 10th Avenue	Toronto	Canada	57375	3
866	George	W	Kennedy	20 74th Avenue	Tokyo	Japan	58094	3
869	Ethan	S	Thomas	22 100th Avenue	Athens	USA	53373	1
872	Lucie	R	Culp	23 80th Avenue	Jerusalem	Israel	90867	6
875	Sophie	R	Peters	24 57th Avenue	Madrid	Spain	67893	3
878	Tim	P	Montgomery	24 90th Avenue	San Francisco	USA	78904	4
881	Crispin	P	Siebert	24 91st Avenue	San Jose	USA	55461	2
884	Pete	O	Pavletich	28 2nd Avenue	Sydney	Austrailia	71380	4
887	Charlene	M	Fiore	29 12th Avenue	Perth	Austrailia	55683	3
890	Ethan	M	Lahoud	29 19th Avenue	San Francisco	USA	67893	3
893	David	M	Nagy	29 20th Avenue	Warsaw	Poland	52152	1
896	Theodore	L	Brett	29 21st Avenue	Maine	USA	90637	5
899	Ethan	L	Derrick	29 24th Avenue	Paris	France	87633	5
902	Luke	K	Romo	29 44th Avenue	Warsaw	Poland	51492	1
905	Tom	J	Koonce	29 51st Avenue	Atlanta	USA	56151	3
908	Roberto	J	Fanzone	3 31 34th Avenue	Maine	USA	90856	5
911	Aristidis	J	Matchick	3 45th Avenue	Brussels	Luxembourg	58093	3
914	Jim	J	Lyle	3 52nd Avenue	San Francisco	USA	71340	4
917	Sunday	G	Lee	3 58th Avenue	San Francisco	USA	57934	3
920	Tamara	G	Lonborg	3 75th Avenue	Paris	France	89745	5
923	George	E	Wagner	3 86th Avenue	Vancouver	Canada	67894	3
926	George	E	Stange	3 95th Avenue	Paris	France	89674	5
929	John	D	Phillips	3 97th Avenue	Brussels	Luxembourg	71395	4
932	Raphael	C	Santiago	30 43rd Avenue	New York	USA	55482	2
935	Pete	A	Moret	31 27th Avenue	Athens	USA	56703	3
938	Nick	T	Hartenstein	32 39th Avenue	Warsaw	Poland	54264	2
941	John	T	Bolin	33 89th Avenue	Warsaw	Poland	56923	3
944	Marie	T	Mills	34 1st Avenue	Toronto	Canada	71309	4
947	Maric	S	Curtis	34 64th Avenue	Toronto	Canada	71369	4
950	Tom	R	Jarvis	34 7th Avenue	Cairo	Egypt	50173	2
953	Jason	P	Alomar	37 61st Avenue	Baghdad	Iraq	57333	3
956	Tom	N	Johnson	37 66th Avenue	Baghdad	Iraq	56923	3
959	Ted	M	Fregosi	4 42nd Avenue	Paris	France	54264	2
962	Crispin	L	Spencer	4 82nd Avenue	Warsaw	Poland	54482	2
965	Jonathan	K	Mcmullen	4 93rd Avenue	Baghdad	Iraq	54329	2
968	Ashvin	J	Repoz	41 60th Avenue	Baghdad	Iraq	89645	5
971	Jim	J	Azcue	42 63rd Avenue	New York	USA	89647	5
974	Shawn	C	Johnstone	43 25th Avenue	Sydney	Austrailia	89034	5
977	Valerie	T	Egan	43 31 35th Avenue	Tokyo	Japan	89634	5
980	Hembert-Glen	T	Voss	4234 66th Avenue	Tokyo	Japan	78904	5
983	Ratco	S	Tatum	45 17th Avenue	Warsaw	Poland	54950	2
986	Ethan	R	Cowan	47 50th Avenue	Maine	France	89674	5
989	Goran	R	Reynolds	47 99th Avenue	Seattle	USA	50555	1
992	Richard	P	Ruiz	47-49 9th Avenue	San Francisco	USA	54152	2
995	Mary	M	Wright	5 40th Avenue	Jerusalem	Israel	55261	2
998	Kristin	M	Gonzalez	5 72nd Avenue	Athens	USA	90845	5
1001	Anri	M	Murphy	51 31 30th Avenue	Paris	France	54262	2
1004	Jim	L	Messersmith	56 98th Avenue	San Francisco	USA	53595	1
1007	Chris	K	May	58 79th Avenue	Toronto	Canada	67893	3
1010	Josef	J	Rodriguez	6 37th Avenue	New York	USA	89645	5
1013	George	J	Griffin	6 46th Avenue	Warsaw	Poland	67893	3
1016	Ethan	J	Rivers	6 55th Avenue	Baghdad	Iraq	54672	2
1019	Andrew	J	Oyler	52nd Buellas Avenue	Madrid	Spain	56593	3
1022	Cecile	J	Bradley	6 KORDUNASKA st	Jerusalem	Israel	78904	5
1025	Tim	J	Queen	4567 Shalam drive	Baghdad	Iraq	57577	3
1028	Mat	H	Silverio	61 11th Avenue	Seattle	USA	89647	5
1031	Bob	G	Garrett	62 54th Avenue	San Francisco	USA	56706	3
1034	Travis	E	Fisher	77th Avenue	London	England	78934	5
1037	Tim	D	Tatum	67 38th Avenue	Warsaw	Poland	50552	1
1040	JING WEN	D	Laroche	7 13th Avenue	Baghdad	Iraq	90784	5
1043	Neithan	D	Reichardt	7 14th Avenue	Athens	USA	78904	5
1046	Joanne	C	Brown	7 48th Avenue	Warsaw	Poland	71338	4
1049	John	C	Kealey	7 83rd Avenue	Maine	USA	90785	5
1052	Gregory	C	Allen	72 78th Avenue	Paris	France	90784	5
1055	Bob	C	Hicks	73 92nd Avenue	Sao Paolo	Brazil	89534	5
1058	Bob	C	Doyle	8 26th Avenue	Tokyo	Japan	90745	5
1061	Ethan	B	Perez	8 67th Avenue	Seattle	USA	57568	3
1064	Kate	B	Cox	83 31 32nd Avenue	New York	USA	96300	6
1067	Nick	B	Shank	85 53rd Avenue	Toronto	Canada	89647	5
1070	Jason	B	Wolf	85-87 68th Avenue	Tokyo	Japan	89643	5
1073	Jonathan	B	May	9 71st Avenue	Jerusalem	Israel	89543	5
1076	Lucie	B	Aparicio	9 85th Avenue	Baghdad	Iraq	89045	5
1079	Robert	R	Melton	\N	Athens	USA	89667	5
1082	Serguie	O	Berry	\N	Seattle	USA	78967	5
1085	Chris	B	O'brien	\N	San Francisco	USA	67894	3
1088	Williams	\N	Knoop	\N	Madrid	Spain	55262	2
1091	Chris	\N	Mccraw	\N	Jerusalem	Israel	54691	2
1094	Alex	\N	Williams	lucinder	Vancouver	Canada	50665	1
1097	Pluto	\N	Herrmann	18 96th Avenue	Paris	France	50501	1
1100	Andrew	\N	Hopkinski	603rd winski road	Warsaw	Poland	50393	3
1103	George	Jack	Josephson	45 west rutherford	Sydney	Austrailia	50393	1
1106	Tim	\N	Spence	168th place	Warsaw	Poland	50287	3
1109	Jason	\N	Mckinney	2 15th Street	Paris	France	50177	2
\.


--
-- Data for Name: language; Type: TABLE DATA; Schema: spy; Owner: -
--

COPY language (lang_id, language) FROM stdin;
1	English
2	Spanish
3	German
4	French
5	Chinese
6	Japanese
7	Russian
8	Polish
9	Arabic
10	Hebrew
11	Cherokee
12	Korean
13	Vietnamese
14	Pashtu
15	Farsi
16	Bengali
17	Malay
18	Portuguese
19	Hindi
20	Turkish
\.


--
-- Data for Name: languagerel; Type: TABLE DATA; Schema: spy; Owner: -
--

COPY languagerel (lang_id, agent_id) FROM stdin;
1	95
1	287
1	312
1	327
1	449
1	469
1	588
1	593
1	785
1	806
1	878
1	1028
2	37
2	45
2	56
2	62
2	64
2	81
2	86
2	100
2	106
2	131
2	134
2	184
2	186
2	189
2	245
2	248
2	260
2	266
2	275
2	283
2	297
2	303
2	311
2	320
2	324
2	361
2	365
2	380
2	382
2	387
2	399
2	403
2	419
2	436
2	437
2	439
2	442
2	448
2	459
2	461
2	465
2	470
2	472
2	476
2	500
2	502
2	504
2	523
2	524
2	526
2	530
2	539
2	540
2	561
2	566
2	574
2	577
2	586
2	595
2	600
2	604
2	704
2	723
2	725
2	730
2	732
2	743
2	748
2	750
2	755
2	775
2	789
2	790
2	806
2	812
2	818
2	833
2	845
2	863
2	869
2	872
2	917
2	923
2	935
2	950
2	1001
2	1007
2	1019
2	1031
2	1049
2	1085
2	1103
3	7
3	31
3	43
3	78
3	95
3	96
3	104
3	105
3	106
3	107
3	112
3	122
3	137
3	145
3	148
3	154
3	173
3	184
3	187
3	189
3	191
3	199
3	202
3	205
3	207
3	209
3	210
3	228
3	235
3	236
3	265
3	272
3	323
3	330
3	335
3	336
3	342
3	346
3	354
3	355
3	359
3	360
3	387
3	395
3	401
3	409
3	410
3	411
3	425
3	442
3	445
3	455
3	457
3	462
3	463
3	465
3	482
3	492
3	500
3	503
3	505
3	507
3	523
3	528
3	530
3	531
3	541
3	542
3	545
3	549
3	558
3	559
3	564
3	571
3	572
3	578
3	579
3	580
3	602
3	603
3	701
3	704
3	705
3	706
3	708
3	711
3	712
3	713
3	715
3	729
3	730
3	737
3	742
3	747
3	752
3	758
3	761
3	763
3	777
3	781
3	783
3	784
3	809
3	830
3	833
3	881
3	917
3	926
3	938
3	953
3	959
3	962
3	965
3	980
3	998
3	1004
3	1016
3	1043
3	1046
3	1088
3	1094
3	1103
4	8
4	39
4	48
4	55
4	72
4	74
4	76
4	82
4	88
4	92
4	95
4	116
4	122
4	133
4	142
4	148
4	159
4	165
4	168
4	169
4	173
4	177
4	193
4	210
4	212
4	219
4	227
4	232
4	236
4	252
4	256
4	260
4	274
4	302
4	324
4	325
4	326
4	330
4	332
4	347
4	366
4	375
4	381
4	389
4	407
4	412
4	414
4	438
4	459
4	463
4	466
4	474
4	477
4	488
4	489
4	496
4	506
4	511
4	512
4	516
4	535
4	558
4	561
4	565
4	581
4	587
4	589
4	600
4	705
4	710
4	717
4	722
4	731
4	745
4	750
4	752
4	762
4	764
4	766
4	768
4	771
4	772
4	774
4	778
4	854
4	860
4	875
4	938
4	947
4	950
4	974
4	977
4	995
4	998
4	1004
4	1010
4	1028
4	1031
4	1037
4	1052
4	1067
5	2
5	12
5	37
5	50
5	59
5	92
5	121
5	124
5	141
5	146
5	157
5	175
5	182
5	185
5	189
5	193
5	202
5	203
5	204
5	247
5	249
5	256
5	262
5	284
5	308
5	326
5	343
5	345
5	350
5	351
5	364
5	367
5	370
5	378
5	384
5	407
5	420
5	428
5	442
5	459
5	479
5	494
5	505
5	525
5	535
5	540
5	559
5	563
5	593
5	594
5	598
5	599
5	705
5	706
5	711
5	722
5	727
5	741
5	749
5	750
5	756
5	766
5	768
5	769
5	775
5	779
5	785
5	789
5	792
5	795
5	806
5	851
5	893
5	953
5	956
5	965
5	974
5	980
5	1025
5	1043
5	1076
5	1109
6	1
6	20
6	21
6	24
6	37
6	55
6	69
6	70
6	80
6	83
6	105
6	125
6	129
6	134
6	140
6	141
6	143
6	149
6	157
6	161
6	193
6	211
6	223
6	229
6	232
6	238
6	239
6	244
6	249
6	252
6	266
6	267
6	271
6	274
6	275
6	283
6	288
6	295
6	307
6	312
6	320
6	323
6	328
6	356
6	360
6	363
6	364
6	366
6	382
6	386
6	389
6	394
6	419
6	426
6	449
6	452
6	453
6	458
6	460
6	472
6	476
6	477
6	496
6	497
6	513
6	518
6	523
6	527
6	531
6	551
6	556
6	566
6	571
6	577
6	580
6	588
6	599
6	700
6	703
6	712
6	715
6	723
6	726
6	727
6	731
6	734
6	736
6	744
6	756
6	757
6	759
6	762
6	765
6	766
6	771
6	774
6	778
6	787
6	791
6	878
6	890
6	896
6	905
6	917
6	929
6	941
6	989
6	1019
6	1031
6	1043
6	1052
6	1079
7	21
7	37
7	55
7	59
7	65
7	72
7	76
7	83
7	95
7	101
7	113
7	134
7	146
7	150
7	154
7	160
7	165
7	173
7	175
7	183
7	191
7	198
7	203
7	209
7	210
7	230
7	254
7	265
7	275
7	279
7	307
7	312
7	319
7	321
7	329
7	335
7	338
7	346
7	351
7	361
7	362
7	382
7	396
7	397
7	398
7	399
7	408
7	410
7	411
7	412
7	416
7	417
7	447
7	452
7	454
7	463
7	470
7	487
7	492
7	510
7	514
7	521
7	528
7	533
7	534
7	539
7	550
7	560
7	563
7	571
7	572
7	582
7	594
7	605
7	706
7	730
7	736
7	741
7	746
7	756
7	758
7	762
7	768
7	772
7	773
7	776
7	781
7	782
7	787
7	788
7	794
7	842
7	848
7	926
7	932
7	947
7	950
7	968
7	977
7	1004
7	1013
7	1064
7	1070
8	21
8	30
8	72
8	74
8	78
8	83
8	87
8	90
8	96
8	99
8	100
8	106
8	112
8	113
8	125
8	130
8	139
8	151
8	164
8	177
8	184
8	188
8	192
8	217
8	223
8	229
8	238
8	240
8	244
8	250
8	265
8	275
8	278
8	288
8	295
8	301
8	306
8	317
8	329
8	332
8	336
8	343
8	353
8	359
8	363
8	365
8	370
8	373
8	375
8	381
8	382
8	386
8	389
8	404
8	407
8	409
8	431
8	436
8	444
8	452
8	460
8	472
8	482
8	484
8	488
8	501
8	508
8	518
8	520
8	526
8	542
8	554
8	574
8	587
8	594
8	595
8	598
8	604
8	705
8	709
8	711
8	727
8	732
8	740
8	744
8	757
8	761
8	777
8	787
8	790
8	791
8	794
8	824
8	872
8	899
8	938
8	956
8	959
8	995
8	1013
8	1040
8	1058
8	1061
8	1079
8	1082
9	4
9	5
9	25
9	27
9	31
9	35
9	45
9	50
9	55
9	71
9	85
9	89
9	92
9	96
9	99
9	100
9	106
9	116
9	124
9	128
9	129
9	146
9	154
9	157
9	160
9	166
9	173
9	178
9	179
9	183
9	190
9	203
9	219
9	229
9	237
9	243
9	244
9	246
9	249
9	252
9	254
9	269
9	295
9	311
9	317
9	332
9	335
9	348
9	350
9	363
9	370
9	375
9	381
9	388
9	391
9	415
9	416
9	426
9	432
9	437
9	439
9	442
9	446
9	460
9	466
9	474
9	484
9	491
9	500
9	514
9	516
9	518
9	521
9	525
9	554
9	557
9	561
9	564
9	566
9	583
9	586
9	588
9	701
9	717
9	719
9	735
9	739
9	740
9	741
9	747
9	748
9	753
9	754
9	755
9	766
9	769
9	784
9	788
9	794
9	795
9	803
9	818
9	839
9	842
9	851
9	857
9	881
9	887
9	902
9	905
9	911
9	962
9	965
9	1019
9	1025
9	1052
9	1055
9	1085
10	1
10	33
10	35
10	39
10	48
10	49
10	62
10	85
10	86
10	105
10	107
10	121
10	139
10	141
10	144
10	155
10	168
10	175
10	185
10	186
10	190
10	199
10	207
10	210
10	219
10	230
10	239
10	240
10	244
10	248
10	262
10	272
10	285
10	288
10	293
10	313
10	326
10	343
10	346
10	348
10	358
10	359
10	361
10	379
10	388
10	395
10	403
10	404
10	408
10	415
10	428
10	429
10	441
10	444
10	453
10	460
10	462
10	470
10	485
10	497
10	505
10	522
10	523
10	524
10	546
10	549
10	555
10	556
10	557
10	581
10	585
10	588
10	703
10	713
10	715
10	742
10	755
10	761
10	763
10	765
10	767
10	780
10	800
10	803
10	851
10	863
10	875
10	890
10	944
10	962
10	977
10	989
10	1007
10	1016
10	1028
10	1043
10	1052
10	1061
10	1064
10	1091
10	1097
11	3
11	21
11	30
11	81
11	82
11	83
11	87
11	90
11	96
11	97
11	113
11	121
11	123
11	127
11	153
11	155
11	159
11	172
11	199
11	200
11	202
11	203
11	207
11	212
11	219
11	223
11	226
11	261
11	265
11	267
11	271
11	280
11	283
11	297
11	317
11	327
11	328
11	329
11	330
11	342
11	343
11	347
11	348
11	353
11	356
11	363
11	366
11	394
11	399
11	418
11	426
11	428
11	429
11	441
11	446
11	459
11	467
11	474
11	476
11	502
11	510
11	519
11	521
11	531
11	540
11	544
11	545
11	546
11	555
11	574
11	577
11	581
11	599
11	601
11	718
11	721
11	723
11	724
11	725
11	734
11	736
11	737
11	746
11	751
11	758
11	759
11	769
11	770
11	774
11	792
11	800
11	803
11	806
11	830
11	875
11	887
11	953
11	962
11	968
11	977
11	989
11	995
11	1028
11	1049
11	1091
12	14
12	36
12	58
12	59
12	70
12	81
12	105
12	107
12	112
12	124
12	133
12	136
12	149
12	167
12	168
12	181
12	182
12	189
12	192
12	206
12	210
12	223
12	228
12	238
12	239
12	243
12	245
12	249
12	257
12	258
12	260
12	271
12	277
12	284
12	306
12	316
12	320
12	323
12	327
12	350
12	353
12	358
12	362
12	386
12	395
12	397
12	398
12	407
12	415
12	416
12	417
12	418
12	422
12	437
12	449
12	472
12	475
12	485
12	490
12	500
12	505
12	510
12	520
12	521
12	525
12	533
12	536
12	539
12	542
12	549
12	550
12	551
12	552
12	557
12	581
12	583
12	595
12	598
12	602
12	606
12	702
12	711
12	716
12	726
12	734
12	735
12	738
12	740
12	742
12	750
12	758
12	759
12	760
12	773
12	777
12	787
12	845
12	854
12	887
12	896
12	911
12	941
12	965
12	977
12	980
12	992
12	1004
12	1013
12	1034
12	1040
12	1088
12	1091
13	2
13	24
13	25
13	35
13	48
13	56
13	70
13	72
13	78
13	84
13	99
13	100
13	105
13	106
13	138
13	146
13	151
13	166
13	172
13	177
13	182
13	185
13	187
13	191
13	201
13	206
13	220
13	232
13	250
13	251
13	252
13	267
13	278
13	281
13	284
13	295
13	302
13	303
13	311
13	312
13	329
13	335
13	360
13	369
13	378
13	386
13	387
13	391
13	403
13	417
13	422
13	431
13	437
13	447
13	465
13	473
13	474
13	479
13	497
13	498
13	499
13	500
13	522
13	523
13	527
13	530
13	543
13	551
13	563
13	564
13	566
13	571
13	577
13	578
13	584
13	593
13	704
13	706
13	707
13	720
13	721
13	723
13	726
13	739
13	742
13	745
13	746
13	748
13	749
13	752
13	772
13	775
13	780
13	792
13	800
13	824
13	833
13	857
13	896
13	911
13	920
13	944
13	980
13	986
13	1031
13	1037
13	1040
13	1049
13	1082
13	1097
13	1106
14	2
14	7
14	45
14	70
14	76
14	83
14	93
14	94
14	100
14	102
14	104
14	107
14	136
14	139
14	151
14	152
14	157
14	159
14	160
14	161
14	165
14	169
14	178
14	180
14	183
14	203
14	204
14	212
14	229
14	243
14	244
14	245
14	246
14	249
14	256
14	260
14	272
14	274
14	275
14	288
14	308
14	326
14	346
14	359
14	363
14	387
14	389
14	399
14	402
14	404
14	407
14	410
14	411
14	431
14	440
14	444
14	450
14	453
14	470
14	485
14	497
14	499
14	505
14	508
14	510
14	526
14	528
14	531
14	533
14	535
14	544
14	551
14	559
14	563
14	580
14	583
14	593
14	707
14	711
14	712
14	714
14	717
14	722
14	726
14	728
14	730
14	732
14	735
14	746
14	756
14	764
14	770
14	773
14	778
14	780
14	785
14	789
14	795
14	800
14	833
14	839
14	857
14	899
14	920
14	938
14	971
14	989
14	1004
14	1055
14	1079
14	1109
15	21
15	25
15	30
15	35
15	61
15	78
15	84
15	93
15	115
15	123
15	130
15	133
15	145
15	148
15	152
15	160
15	163
15	164
15	168
15	173
15	188
15	189
15	202
15	219
15	221
15	223
15	226
15	229
15	256
15	257
15	258
15	266
15	271
15	284
15	297
15	299
15	309
15	324
15	327
15	329
15	339
15	350
15	351
15	352
15	358
15	362
15	364
15	374
15	375
15	378
15	381
15	382
15	385
15	397
15	402
16	404
15	409
15	414
15	415
15	417
15	428
15	444
15	450
15	455
15	476
15	488
15	498
15	501
15	524
15	549
15	550
15	565
15	588
15	594
15	599
15	600
15	709
15	715
15	717
15	733
15	746
15	748
15	759
15	765
20	766
15	776
15	785
15	789
15	792
15	827
15	860
15	872
15	875
15	884
15	899
15	914
15	950
15	962
15	980
15	983
15	1010
15	1022
15	1058
15	1076
15	1097
15	1100
16	24
16	48
16	50
16	89
16	101
16	104
16	127
16	136
16	140
16	145
16	150
16	161
16	164
16	169
16	180
16	192
16	193
16	212
16	248
16	257
16	261
16	262
16	297
16	315
16	324
16	327
16	351
16	352
16	365
16	367
16	370
16	395
16	397
16	408
16	409
16	414
16	422
16	429
16	431
16	457
16	464
16	467
16	470
16	481
16	494
16	501
16	511
16	516
16	520
16	526
16	528
16	541
16	547
16	551
16	561
16	563
16	598
16	604
16	700
16	706
16	729
16	744
16	749
16	759
16	771
16	780
16	782
16	787
16	793
16	809
16	857
16	872
16	917
16	956
16	959
16	974
16	992
16	998
16	1010
16	1013
16	1022
16	1040
16	1055
16	1058
16	1073
16	1088
16	1097
16	1106
17	12
17	20
17	22
17	30
17	31
17	39
17	55
17	59
17	90
17	99
17	112
17	123
17	126
17	148
17	149
17	164
17	168
17	172
17	174
17	177
17	180
17	190
17	198
17	201
17	230
17	239
17	245
17	246
17	257
17	262
17	276
17	286
17	306
17	311
17	312
17	317
17	324
17	332
17	336
17	342
17	352
17	355
17	365
17	379
17	399
17	404
17	418
17	419
17	423
17	427
17	429
17	448
17	449
17	454
17	463
17	467
17	469
17	474
17	496
17	497
17	503
17	508
17	511
17	517
17	520
17	537
17	538
17	539
17	545
17	598
17	600
17	602
17	700
17	716
17	725
17	730
17	732
17	733
17	734
17	752
17	754
17	757
17	761
17	783
17	794
17	803
17	815
17	845
17	857
17	860
17	947
17	950
17	959
17	965
17	992
17	998
17	1025
17	1028
17	1031
17	1052
17	1055
17	1091
18	3
18	22
18	35
18	43
18	56
18	71
18	76
18	81
18	88
18	95
18	96
18	104
18	108
18	113
18	121
18	124
18	146
18	148
18	151
18	152
18	167
18	170
18	172
18	174
18	181
18	186
18	188
18	202
18	232
18	233
18	239
18	243
18	250
18	278
18	285
18	302
18	303
18	306
18	308
18	320
18	323
18	330
18	335
18	350
18	352
18	353
18	361
18	373
18	375
18	377
18	393
18	408
18	436
18	440
18	441
18	448
18	450
18	457
18	462
18	463
18	481
18	498
18	508
18	513
18	520
18	525
18	529
18	535
18	537
18	540
18	542
18	545
18	555
18	559
18	560
18	572
18	577
18	585
18	591
18	606
18	701
18	704
18	714
18	715
18	727
18	733
18	734
18	741
18	742
18	743
18	754
18	757
18	760
18	773
18	786
18	815
18	836
18	839
18	884
18	902
18	911
18	914
18	929
18	956
18	992
18	1040
18	1079
18	1085
19	7
19	33
19	50
19	71
19	76
19	81
19	84
19	91
19	107
19	112
19	125
19	127
19	132
19	133
19	161
19	167
19	183
19	191
19	192
19	200
19	217
19	221
19	232
19	233
19	252
19	254
19	266
19	283
19	284
19	287
19	307
19	323
19	328
19	332
19	339
19	343
19	355
19	360
19	370
19	386
19	403
19	405
19	410
19	418
19	421
19	422
19	428
19	446
19	451
19	458
19	459
19	466
19	469
19	475
19	476
19	482
19	484
19	485
19	501
19	512
19	518
19	521
19	532
19	538
19	539
19	541
19	544
19	546
19	561
19	589
19	601
19	606
19	700
19	717
19	731
19	733
19	737
19	738
19	740
19	745
19	747
19	760
19	762
19	772
19	779
19	780
19	786
19	790
19	818
19	821
19	839
19	866
19	884
19	896
19	908
19	911
19	914
19	932
19	935
19	941
19	947
19	956
19	959
19	992
19	998
19	1010
19	1025
19	1034
19	1097
19	1103
20	7
20	20
20	43
20	49
20	50
20	78
20	84
20	85
20	92
20	104
20	131
20	149
20	175
20	178
20	180
20	182
20	188
20	191
20	200
20	201
20	220
20	221
20	236
20	237
20	238
20	240
20	245
20	254
20	257
20	271
20	272
20	283
20	288
20	320
20	326
20	330
20	345
20	353
20	395
20	403
20	411
20	414
20	420
20	429
20	432
20	440
20	444
20	449
20	452
20	466
20	472
20	488
20	491
20	501
20	511
20	512
20	530
20	536
20	538
20	540
20	541
20	555
20	556
20	581
20	582
20	583
20	601
20	701
20	707
20	716
20	729
20	733
20	748
20	753
20	760
20	761
20	771
20	773
20	785
20	792
20	821
20	878
20	905
20	908
20	986
20	1007
20	1016
20	1043
20	1073
20	1085
\.

--
-- Data for Name: mission; Type: TABLE DATA; Schema: spy; Owner: -
--

COPY mission (mission_id, name, access_id, team_id, mission_status) FROM stdin;
1	Third Age	5	12	success
2	White Crown	5	12	failed
3	Galbassi	3	30	success
4	Gollum	6	13	ongoing
5	Mellyrn	3	10	ongoing
6	Norland	2	18	ongoing
7	Oliphaunt	5	28	failed
8	Hornblower	2	10	success
9	Cair Andros	6	11	ongoing
10	Black Crown	6	19	success
11	Guarded City	1	20	ongoing
12	Methedras	1	15	success
13	Silpion	4	19	ongoing
14	Wandlimb	4	8	ongoing
15	Barrow wights	5	11	success
16	Dark Years	4	11	success
17	Elbereth	5	12	ongoing
18	Black Country	2	18	success
19	Nazgul	6	8	failed
20	Seat of Seeing	7	6	success
21	Tighfield	5	13	ongoing
22	Deeping Stream	6	14	ongoing
23	Adaldrida	3	4	ongoing
24	Annatar	4	5	ongoing
25	Lith	6	20	success
26	Crystal Crown	7	29	success
27	Entings	5	14	success
28	Closed Door	6	19	success
29	Black	6	22	success
30	Pimple	4	1	failed
31	Rath Celerdain	7	4	ongoing
32	Diaz	6	33	failed
33	Brandy Hall	5	8	ongoing
34	Hornrock	2	11	ongoing
35	Shirriffs	7	12	success
36	Old Forest	1	24	failed
37	Swertings	4	22	success
38	Maura	1	14	success
39	Galpsi	1	28	failed
40	Middle Days	3	17	ongoing
41	Orcs	1	31	failed
42	Beleriand	5	13	failed
43	Bofur	1	4	success
44	Secret Fire	6	7	ongoing
45	Merethrond	6	13	failed
46	Narcguest	2	4	ongoing
47	Onodrim	6	29	success
48	Sandyman the Miller	6	10	ongoing
49	Bolgraten	7	1	failed
50	Iron Comb	1	30	success
51	Hammer of the Underw	3	3	ongoing
52	North Downs	3	19	ongoing
53	Karan	1	7	success
54	Fell Winter	1	20	success
55	Delving	2	16	success
56	Nob	1	17	ongoing
57	Parth Galen	7	37	success
58	Biggie Smalls	4	36	failed
59	Gold King	3	25	success
60	Floating Log	2	3	ongoing
61	Middle Earth	7	3	success
62	Downlands	2	4	success
63	Balrog	3	8	success
64	Stewards	3	20	ongoing
65	Old World	4	27	ongoing
66	Palantiri	4	34	success
67	Aulendil	6	7	success
68	Underhill	2	3	failed
69	Derndingle	7	17	success
70	Narchost	1	3	success
71	Stybba	3	21	failed
72	Heathertoes	7	6	ongoing
73	Tower of the Sun	7	16	ongoing
74	Town Hole	7	19	ongoing
75	Bregalad	6	3	success
76	Banana	7	34	success
77	Twofoot	1	2	ongoing
78	Curtain	3	8	failed
79	Gimli	4	10	ongoing
80	Minas Anor	4	18	ongoing
81	Of the Eye	2	32	ongoing
82	Old Man	6	11	failed
83	Mathom-house	2	9	ongoing
84	Nimbrethil	4	13	failed
85	Targon	4	3	ongoing
86	Red Arrow	3	19	ongoing
87	Naith	5	40	success
88	Carbandur	6	24	failed
89	Carbandelsic	5	39	ongoing
90	Durin Bridge	5	7	ongoing
91	Watchwood	4	8	failed
92	Pipe Weed	5	2	failed
93	Tupac	3	35	ongoing
94	Sirion	4	12	success
95	Strawheads	3	2	success
96	Overhill	4	13	success
97	Great Darkness	6	17	success
98	Mitheithel	2	23	failed
99	Anduin	3	32	ongoing
100	Wandering Companies	3	6	failed
101	Causeway	3	14	success
102	Tuckborough	1	20	ongoing
103	Muzgash	4	39	ongoing
104	Sarn Ford	7	11	failed
105	Calacirian	7	12	success
106	Suza	2	1	failed
107	Galdor	2	24	failed
108	Helm Deep	7	6	ongoing
109	Isengard	3	14	ongoing
110	Oldbuck	7	23	failed
111	Singollo	1	37	success
112	Ambarona	1	2	success
113	Moria	7	6	failed
114	Older Days	2	13	success
115	Orophin	3	33	failed
116	Cirion	5	18	ongoing
117	Mindolluin	7	21	failed
118	Hamanullas	6	26	ongoing
119	Vala Aule	7	8	failed
120	Crack of Doom	2	5	ongoing
121	Sharkey End	6	12	failed
122	Mirkwood	4	33	failed
123	Durin Stone	3	7	ongoing
124	Denethor	7	17	success
125	Northern Fences	4	20	failed
126	Firefoot	2	3	success
127	Golden Perch	5	13	success
128	Underharrow	2	2	failed
129	Westron	3	12	ongoing
130	Pillars of the King	5	14	ongoing
131	Pelargir	2	39	ongoing
132	Ram	5	11	failed
133	Hidden Land	7	7	success
134	Thistlewool	5	12	ongoing
135	Paths of the Dead	1	38	failed
136	Karningul	7	25	success
137	Eregion	2	17	ongoing
138	Fenmarch	1	1	ongoing
139	Chamber of Mazarbul	4	16	success
140	Younger Days	1	20	failed
141	Outlands	6	36	failed
142	Goodbodies	5	14	success
143	Kharas	3	3	success
144	EasyE	6	38	failed
145	Kastic	4	24	failed
146	Galadriel	5	20	failed
147	Dimrill Stair	1	2	ongoing
148	Deeping Wall	6	15	ongoing
149	Lagduf	4	16	ongoing
150	Fair Folk	7	17	ongoing
151	Gate of Kings	3	7	success
152	The Haunted Pass	6	9	ongoing
153	Banakil	1	2	failed
154	New Row	3	12	success
155	Phur	6	12	success
156	Eastfarthing	4	10	success
157	Mountains of Lune	7	35	ongoing
158	Pippin	4	10	ongoing
159	Medusa	7	3	success
160	Court of the Fountai	2	4	ongoing
161	Brockenbores	6	9	success
162	Silent Street	1	13	ongoing
163	Southfarthing	2	19	success
164	Morgoth	1	9	ongoing
165	Esmeralda	3	15	failed
166	Numenor	4	11	failed
167	Shelob	4	15	success
168	Gold Thief	5	27	ongoing
169	Zara	1	26	ongoing
170	Desk Top	3	37	success
171	Nameless Pass	2	6	success
172	Dark Days	4	11	failed
173	Last Alliance	5	16	ongoing
174	Fangorn	6	17	ongoing
175	Twilight	5	12	success
176	Neekerbreekers	7	9	ongoing
177	RAUTA	5	5	ongoing
178	Goose	7	28	failed
179	Pickthorn	3	40	success
180	Sammath Naur	2	13	failed
181	Nargian	5	18	ongoing
182	The Tongue	6	9	ongoing
183	Tharni	2	34	success
184	Soval Phare	5	4	ongoing
185	Gilrain	4	8	success
186	Shadow Host	5	9	success
187	Towers of the Teeth	7	17	failed
188	The Creeper	7	39	ongoing
189	Brave Brando	7	22	success
190	Aldor	1	1	success
191	Saradoc	4	3	ongoing
192	Great Jewel	1	18	success
193	Maverick	1	29	success
194	Gandalf	7	7	failed
195	Turac	2	27	ongoing
196	Melkor	1	16	success
197	Gladden River	4	10	ongoing
198	Tookland	6	15	success
199	Grim Reeper	1	40	success
200	Minas Tirith	2	10	ongoing
201	Sindarin	5	34	success
202	Black Land	7	1	ongoing
203	Westfarthing	5	10	failed
204	Bruinen River	6	11	ongoing
205	Elves	5	14	failed
206	Old Winyards	3	26	ongoing
207	The Renewer	2	6	failed
208	Sindar	6	35	ongoing
209	Baldor	3	6	success
210	Dead City	5	12	ongoing
211	Iron Crown	3	13	failed
212	Chicken Burrito	4	31	failed
213	Lobelia	4	1	failed
214	Haunted Pass	6	3	failed
215	The Wise	7	10	ongoing
216	Anak	6	6	failed
217	Radiant Tree	6	21	failed
218	Hall of the Kings	4	1	ongoing
219	Rushlight	3	2	failed
220	Wormtongue	3	18	failed
221	Nehald	4	17	ongoing
222	Cardigan	4	38	failed
223	Book of Mazarbul	2	6	success
224	Shadowmere	6	10	ongoing
225	Grayhame	6	17	failed
226	Mouth of Sauron	1	36	failed
227	Nindalf	6	15	success
228	Gamba	2	29	success
229	Morgul Vale	3	31	failed
230	Leaflock	5	18	ongoing
231	Morgul Pass	2	30	success
232	Belfalas	6	15	success
233	Minas Morgul	6	20	failed
234	Noakes	7	16	success
235	Barrow Blade	4	11	success
236	Melian	6	14	success
237	Arathorn	2	5	success
238	Nenya	1	7	ongoing
239	Beorn	6	16	success
240	Rog	6	5	ongoing
241	Gelion	2	31	failed
242	Taniquetil	4	4	ongoing
243	Prancing Pony	6	16	failed
244	Sarn Gebir	1	12	success
245	Tobias	1	33	failed
246	Valinor	3	39	ongoing
247	Cormallen	7	2	ongoing
248	Vilya	1	5	failed
249	Crickhollow	2	7	success
250	Tower Hills	6	15	ongoing
251	Black Captain	6	18	success
252	Hither Shore	2	8	ongoing
253	Nimloth	5	14	success
254	IceT	5	37	success
255	Black Downs	6	1	ongoing
256	Crossroads	3	7	success
257	Silent Watchers	1	14	failed
258	Miruvor	1	22	success
259	Dome of Stars	2	4	failed
260	Bombur	1	5	ongoing
261	Battle of the Peak	1	13	success
262	Gorbadoc	3	15	success
263	Riddermark	3	19	failed
264	Northern Fences	1	9	failed
265	Woodland Realm	1	18	ongoing
266	Scatha the Worm	3	14	success
267	Staddle	1	19	ongoing
268	Mordor	3	4	ongoing
269	Eilenach	4	11	success
270	Wingfoot	7	15	failed
271	Radbug	2	17	ongoing
272	Old Toby	2	25	success
273	Harfoots	5	25	success
274	Treebeard	1	19	ongoing
275	Anduril	5	7	success
276	Thingol Backard	2	38	failed
277	Appledore	2	5	success
278	Dernhelm	7	18	failed
279	Mithlond Pillar	7	36	failed
280	Council of the Wise	1	4	ongoing
281	Fen Hollen	1	20	success
282	Mithlond	3	24	failed
283	Nameless	6	1	failed
284	Neldoreth	1	10	ongoing
285	Smial	3	2	failed
286	Companions	7	1	success
287	The Eldar	4	6	ongoing
288	Last Shore	5	17	success
289	Mithril	4	25	success
290	Tung	3	28	failed
291	Raisen	2	8	failed
292	Smeagol	2	17	ongoing
293	Gradulivic	7	27	ongoing
294	Angbor	2	3	success
295	Merlin	6	27	ongoing
296	Osgiliath	5	35	ongoing
297	Elu Thingol	7	15	success
298	Galathilion	1	23	failed
299	Bamfurlong	4	8	success
300	Goatleaf	5	11	ongoing
301	Minas Ithil	5	19	ongoing
302	South Road	7	18	ongoing
303	Kalimac	3	23	failed
304	Sunlending	3	2	ongoing
305	Eastfold	3	10	success
306	Young Tom	1	19	failed
307	Morgulduin	4	32	ongoing
308	Mount Doom	5	33	failed
309	Mount Everwhite	6	34	success
310	Rath Dinen	1	5	ongoing
311	Widow	5	9	ongoing
312	Window of the Eye	1	15	ongoing
313	Dimholt	1	19	ongoing
314	Common Speech	7	1	failed
315	Holman	4	10	failed
316	Deeping Coomb	5	14	ongoing
317	Skinbark	1	16	ongoing
318	Grey Host	4	20	ongoing
319	Orcrist	7	30	success
320	Riders of Rohan	4	8	failed
321	Angband	3	11	failed
322	Talath Dirnen	4	40	success
323	Eagles	3	8	success
324	Valandil	3	5	ongoing
325	Smallburrow	5	16	success
326	Tuca	4	29	success
327	Dimrill Dale	1	1	success
328	Second Age	5	6	ongoing
329	West Marches	2	9	failed
330	Beechbone	5	15	success
331	RAMBA	7	7	success
332	Morgai	5	26	ongoing
333	Watergate	6	28	failed
334	Sandheaver	4	2	success
335	Shadowfax	5	9	success
336	Lightfoot	6	20	failed
337	Aldaron	1	1	failed
338	Republic	1	35	ongoing
339	Artano	5	6	failed
340	Galadrim	3	5	success
341	Silvertine	7	16	success
342	Mundburg	3	38	failed
343	Hay Gate	6	4	ongoing
344	Battle of Five Armie	5	12	success
345	Gold Demon	4	26	ongoing
346	City of the Trees	3	18	ongoing
347	Mellon	1	8	failed
348	Tragu	7	32	ongoing
349	Orahunter	3	9	ongoing
350	Saruman	4	4	failed
351	The Farthings	7	7	failed
352	Mugwort	2	37	success
353	Flourdumpling	7	4	success
354	The Barney	2	5	ongoing
355	Bridge of Stonebows	5	8	ongoing
356	Ringwraiths	3	7	success
357	Bolgra	5	23	failed
358	Nine Walkers	4	9	ongoing
359	Farmer Tom	1	18	success
360	Rasputin	7	13	failed
361	Houses of Healing	4	13	ongoing
362	Wizard Vale	7	16	failed
363	Trahan	5	30	success
364	Lograd	7	20	failed
365	Labin	1	21	failed
366	Baraz	4	9	success
367	Damrod	3	9	ongoing
368	Stoors	2	20	failed
369	Bilbo	2	3	success
370	Black Pit	7	2	success
371	Northfarthing	4	10	success
372	Proudfoot	2	16	success
373	Narsil	4	6	failed
374	Trahald	6	31	failed
375	Mathom	2	15	success
376	Brandu	6	40	success
377	Nanduhirion	7	2	failed
378	Narrow Ice	3	5	ongoing
379	Sharku	4	3	success
380	Razar	7	6	failed
381	Woodburn	2	36	failed
382	Dunharrow	2	5	failed
383	White Downs	5	13	failed
384	Stair Falls	2	19	success
385	Rohan	2	20	success
386	North Kingdom	5	21	failed
387	Nowbourn	6	17	ongoing
388	Aglarond	1	1	success
389	Blessed Realm	3	4	success
390	Carach Angren	2	14	success
391	Celos	4	15	ongoing
392	Mere of Dead Faces	7	14	success
393	Nen Hithoel	2	11	failed
394	Lothran	3	16	success
395	Galad	3	18	ongoing
396	Aman	2	2	failed
397	Tharbad	4	5	success
398	Lohtur	6	19	ongoing
399	Kuduk	2	22	success
400	Francisco	5	32	ongoing
402	Media Blanket	1	42	ongoing
404	Green Lantern	2	44	ongoing
406	Y2K defense	3	44	success
408	Code Red Worm Attack	3	44	failed
\.
--
-- Data for Name: securityclearance; Type: TABLE DATA; Schema: spy; Owner: -
--

COPY securityclearance (sc_id, sc_level, description) FROM stdin;
1	Presidential	Highest level of access
2	Majestic	Second highest level of access
3	Magellon	Third highest level of access
4	Top Secret	Fourth highest level of access
5	Secret	Fifth highest level of access
6	Classified	Second lowest clearance
7	Unclassified	Lowest level of clearance
\.


--
-- Data for Name: skill; Type: TABLE DATA; Schema: spy; Owner: -
--

COPY skill (skill_id, skill) FROM stdin;
1	Sniper
2	Demolition Expert
3	Driver
4	Computer Hacker
5	Communications
6	Electronic Engineer
7	Chemical Expert
8	Blackbelt - Karate
9	Cryptographer
10	Electronic Technicia
11	Biologist
12	Physicist
13	Information Technolo
14	Foreign Linguist
15	Intelligence Researc
16	Investigative Specia
17	Personnel Security S
18	Administrative Servi
19	Counterterrorism
20	Ethics Law Enforceme
21	Computer Forensics
22	Informant developmen
23	Evidence collection
24	Counterintelligence
25	Human Behavior
26	Constitutional Crimi
27	Physical Defense tac
28	Firearms
29	Logistics
30	Extraterrestrial Spe
31	DNA Forensics
32	Extra Sensory Percep
33	Smuggler
34	Diplomatic Specialis
35	Lip Reader
36	Speed Reader
37	Seduction/Sex Appeal
38	Charisma
39	Forgery
40	Leadership
41	Craftsman
42	Meteorology
43	Medicine
44	Calligraphy
45	Stenography
46	Torture
47	Theology
48	Pilot
49	Navigations Expert
50	Acrobatics
51	Financial Expert
52	Locksmith
53	Archeology
54	Kung Fu
55	VooDoo/Blackmagic
56	Agent Handling
57	Surveillance
58	Eavesdropping
59	Concealment Devices
60	Acounstics
61	Nuclear Intelligence
62	Radar Intelligence
63	Hostage retrieval
64	Assassination
65	Material Intelligenc
66	Interrogation
\.


--
-- Data for Name: skillrel; Type: TABLE DATA; Schema: spy; Owner: -
--

COPY skillrel (skill_id, agent_id) FROM stdin;
1	168
1	207
1	543
2	22
2	36
2	50
2	101
2	161
2	175
2	193
2	204
2	267
2	278
2	281
2	312
2	346
2	350
2	388
2	517
2	559
2	703
2	716
2	723
2	803
2	821
2	836
2	1040
3	4
3	159
3	193
3	226
3	277
3	324
3	339
3	345
3	362
3	418
3	426
3	445
3	451
3	537
3	555
3	577
3	581
3	720
3	729
3	947
3	983
3	986
3	1106
4	30
4	49
4	72
4	97
4	121
4	149
4	178
4	260
4	303
4	386
4	398
4	420
4	425
4	427
4	442
4	446
4	455
4	487
4	500
4	503
4	559
4	580
4	581
4	734
4	863
4	968
4	1043
5	35
5	71
5	80
5	104
5	134
5	189
5	227
5	235
5	313
5	429
5	439
5	455
5	479
5	531
5	559
5	574
5	725
5	729
5	739
5	742
5	750
5	791
5	803
5	887
5	998
5	1055
6	20
6	33
6	49
6	74
6	84
6	88
6	101
6	102
6	151
6	177
6	201
6	206
6	232
6	311
6	426
6	437
6	472
6	476
6	497
6	521
6	534
6	599
6	720
6	760
6	776
6	926
7	62
7	64
7	151
7	160
7	186
7	192
7	217
7	223
7	266
7	280
7	323
7	348
7	361
7	369
7	404
7	409
7	463
7	489
7	501
7	516
7	519
7	529
7	536
7	723
7	726
7	732
7	750
7	755
7	762
7	775
7	790
7	881
7	923
7	938
7	947
7	1031
7	1064
8	4
8	72
8	144
8	174
8	183
8	247
8	249
8	303
8	366
8	385
8	396
8	438
8	445
8	461
8	485
8	521
8	547
8	563
8	588
8	605
8	720
8	770
8	773
8	806
8	860
8	920
8	959
8	1076
8	1100
9	93
9	137
9	172
9	179
9	236
9	265
9	309
9	328
9	343
9	352
9	374
9	380
9	384
9	411
9	421
9	427
9	445
9	451
9	467
9	490
9	591
9	702
9	704
9	708
9	719
9	724
9	740
9	761
9	777
9	781
9	890
9	1019
9	1022
9	1079
9	1100
10	22
10	90
10	100
10	115
10	122
10	139
10	206
10	220
10	240
10	247
10	302
10	347
10	388
10	472
10	496
10	514
10	546
10	560
10	591
10	600
10	603
10	716
10	725
10	739
10	792
10	800
10	893
10	1034
11	36
11	50
11	100
11	102
11	116
11	137
11	154
11	188
11	210
11	233
11	239
11	271
11	272
11	283
11	285
11	288
11	308
11	320
11	335
11	336
11	369
11	375
11	423
11	501
11	532
11	604
11	606
11	704
11	707
11	737
11	742
11	754
11	772
11	806
11	860
11	980
11	1007
11	1013
11	1028
11	1040
11	1046
11	1085
12	30
12	99
12	107
12	150
12	163
12	173
12	193
12	240
12	274
12	307
12	359
12	410
12	467
12	470
12	494
12	496
12	529
12	557
12	574
12	747
12	788
12	848
12	866
12	965
12	971
12	1004
13	22
13	45
13	50
13	70
13	100
13	128
13	139
13	174
13	190
13	220
13	269
13	332
13	380
13	387
13	407
13	415
13	425
13	451
13	466
13	469
13	481
13	482
13	484
13	508
13	527
13	551
13	591
13	732
13	737
13	768
13	786
13	792
13	962
13	992
13	1058
13	1082
14	33
14	74
14	90
14	132
14	178
14	238
14	261
14	266
14	267
14	275
14	283
14	301
14	324
14	335
14	354
14	407
14	417
14	420
14	440
14	445
14	454
14	463
14	473
14	475
14	490
14	534
14	539
14	589
14	599
14	722
14	729
14	731
14	775
14	781
14	818
14	827
14	842
14	1049
14	1073
14	1085
15	8
15	58
15	81
15	92
15	116
15	186
15	230
15	262
15	359
15	429
15	438
15	449
15	465
15	500
15	522
15	726
15	746
15	755
15	818
15	836
15	899
15	941
15	944
15	1097
16	24
16	31
16	59
16	129
16	140
16	146
16	185
16	199
16	299
16	370
16	374
16	378
16	386
16	420
16	423
16	446
16	470
16	474
16	504
16	507
16	527
16	528
16	536
16	557
16	584
16	713
16	722
16	739
16	941
16	1040
16	1064
17	7
17	12
17	14
17	141
17	150
17	169
17	187
17	221
17	227
17	260
17	262
17	359
17	373
17	385
17	409
17	426
17	439
17	514
17	519
17	538
17	549
17	563
17	721
17	767
17	773
17	786
17	793
17	812
17	923
17	986
17	989
17	1031
17	1034
18	1
18	69
18	74
18	175
18	185
18	201
18	209
18	228
18	232
18	303
18	360
18	363
18	420
18	477
18	494
18	518
18	543
18	560
18	599
18	711
18	760
18	785
18	821
18	851
18	944
18	977
18	992
18	1043
19	48
19	56
19	125
19	153
19	161
19	174
19	180
19	203
19	209
19	272
19	293
19	346
19	352
19	401
19	405
19	417
19	441
19	482
19	490
19	501
19	523
19	552
19	574
19	582
19	705
19	764
19	899
19	1004
19	1049
19	1097
20	12
20	192
20	243
20	256
20	260
20	307
20	323
20	360
20	393
20	459
20	460
20	470
20	485
20	490
20	538
20	550
20	705
20	738
20	757
20	795
20	833
20	860
20	1049
20	1097
20	1106
21	8
21	106
21	153
21	174
21	184
21	203
21	276
21	301
21	324
21	348
21	373
21	436
21	487
21	603
21	731
21	766
21	824
21	830
21	854
21	947
21	956
21	980
21	983
21	1007
22	3
22	65
22	81
22	89
22	113
22	122
22	124
22	186
22	212
22	227
22	258
22	297
22	345
22	352
22	416
22	421
22	466
22	477
22	513
22	522
22	532
22	541
22	558
22	705
22	734
22	738
22	788
22	806
22	809
22	953
23	70
23	104
23	168
23	230
23	238
23	245
23	284
23	316
23	364
23	395
23	403
23	427
23	436
23	440
23	529
23	556
23	558
23	722
23	756
23	763
23	854
23	869
23	902
23	992
23	1019
23	1067
24	3
24	59
24	64
24	81
24	82
24	95
24	106
24	108
24	125
24	139
24	177
24	178
24	182
24	209
24	271
24	320
24	332
24	362
24	386
24	402
24	461
24	466
24	503
24	524
24	534
24	541
24	563
24	588
24	707
24	712
24	747
24	758
24	770
24	782
24	815
24	920
24	932
24	974
24	1040
24	1082
25	8
25	33
25	91
25	108
25	133
25	179
25	204
25	249
25	281
25	287
25	307
25	354
25	359
25	384
25	386
25	409
25	513
25	523
25	535
25	539
25	543
25	546
25	713
25	716
25	718
25	782
25	896
25	1070
26	4
26	87
26	160
26	182
26	193
26	240
26	276
26	303
26	346
26	377
26	388
26	412
26	428
26	476
26	530
26	542
26	550
26	559
26	703
26	740
26	767
26	768
26	769
26	771
26	787
26	791
26	863
26	893
26	1061
26	1067
26	1097
27	125
27	205
27	219
27	250
27	284
27	288
27	321
27	342
27	355
27	423
27	488
27	489
27	556
27	565
27	587
27	605
27	721
27	746
27	763
27	787
27	839
27	866
27	869
27	899
27	902
27	905
27	965
27	986
27	1010
27	1109
28	1
28	24
28	30
28	45
28	56
28	70
28	89
28	153
28	187
28	201
28	202
28	206
28	244
28	257
28	258
28	276
28	284
28	316
28	323
28	339
28	373
28	428
28	429
28	437
28	446
28	461
28	514
28	540
28	543
28	577
28	756
28	787
28	809
28	908
28	986
28	1001
28	1004
28	1010
28	1022
28	1025
28	1031
28	1091
29	37
29	85
29	90
29	96
29	145
29	165
29	220
29	229
29	239
29	246
29	247
29	306
29	370
29	389
29	414
29	425
29	510
29	540
29	731
29	753
29	756
29	764
29	767
29	780
29	794
29	827
29	1082
30	39
30	55
30	96
30	142
30	143
30	249
30	261
30	323
30	327
30	332
30	361
30	370
30	378
30	379
30	411
30	441
30	462
30	467
30	513
30	516
30	528
30	538
30	559
30	586
30	598
30	707
30	766
30	775
30	776
30	779
30	908
30	986
30	1025
30	1055
30	1076
31	94
31	97
31	152
31	184
31	198
31	199
31	220
31	245
31	249
31	254
31	258
31	274
31	309
31	364
31	499
31	503
31	517
31	587
31	727
31	860
31	941
31	953
31	983
31	995
31	1052
32	31
32	39
32	148
32	152
32	185
32	190
32	254
32	343
32	388
32	412
32	458
32	514
32	545
32	546
32	551
32	583
32	719
32	726
32	748
32	774
32	917
32	923
32	983
32	1034
32	1079
33	61
33	104
33	112
33	121
33	144
33	148
33	152
33	168
33	227
33	327
33	428
33	450
33	477
33	489
33	565
33	584
33	605
33	723
33	738
33	753
33	774
33	781
33	827
33	851
33	887
33	971
33	998
34	27
34	61
34	170
34	182
34	319
34	325
34	473
34	496
34	502
34	518
34	549
34	555
34	584
34	733
34	887
34	995
34	1013
34	1019
34	1070
35	14
35	21
35	33
35	59
35	82
35	192
35	272
35	283
35	365
35	411
35	419
35	441
35	453
35	510
35	517
35	529
35	534
35	560
35	578
35	603
35	605
35	705
35	715
35	851
35	926
35	959
35	1085
36	1
36	71
36	113
36	115
36	160
36	182
36	183
36	200
36	238
36	248
36	260
36	319
36	379
36	384
36	408
36	421
36	492
36	526
36	547
36	552
36	701
36	719
36	756
36	851
36	887
36	917
36	953
36	1073
37	5
37	92
37	166
37	179
37	202
37	235
37	250
37	352
37	394
37	401
37	416
37	508
37	512
37	513
37	537
37	542
37	722
37	745
37	771
37	809
37	896
37	998
37	1031
37	1037
37	1076
38	61
38	65
38	89
38	152
38	174
38	179
38	249
38	272
38	288
38	339
38	381
38	426
38	450
38	451
38	458
38	474
38	484
38	527
38	535
38	551
38	587
38	588
38	717
38	724
38	725
38	734
38	781
38	836
38	854
38	857
38	884
38	974
38	1004
38	1013
38	1034
39	1
39	95
39	124
39	139
39	170
39	221
39	276
39	326
39	378
39	429
39	447
39	469
39	488
39	523
39	538
39	552
39	557
39	561
39	601
39	766
39	767
39	830
39	887
39	947
39	1022
39	1055
39	1085
40	50
40	56
40	108
40	155
40	177
40	188
40	207
40	212
40	227
40	237
40	251
40	262
40	280
40	287
40	293
40	330
40	332
40	396
40	457
40	474
40	564
40	582
40	598
40	792
40	1022
40	1043
40	1055
40	1073
40	1085
40	1106
41	49
41	50
41	56
41	90
41	124
41	150
41	157
41	175
41	210
41	229
41	274
41	295
41	306
41	335
41	345
41	355
41	409
41	416
41	428
41	441
41	476
41	519
41	533
41	571
41	599
41	715
41	743
41	793
41	872
41	884
41	962
42	7
42	48
42	55
42	70
42	113
42	164
42	168
42	281
42	311
42	317
42	329
42	360
42	361
42	374
42	409
42	423
42	439
42	462
42	466
42	474
42	482
42	530
42	537
42	563
42	565
42	710
42	758
42	971
42	1007
43	83
43	102
43	150
43	167
43	210
43	211
43	250
43	275
43	277
43	295
43	339
43	365
43	415
43	520
43	531
43	537
43	554
43	556
43	564
43	577
43	585
43	711
43	714
43	768
43	854
43	866
44	39
44	45
44	58
44	61
44	85
44	104
44	113
44	124
44	169
44	186
44	256
44	320
44	365
44	408
44	419
44	441
44	442
44	528
44	552
44	557
44	604
44	606
44	714
44	721
44	752
44	795
44	851
44	1064
45	69
45	71
45	106
45	116
45	144
45	145
45	146
45	152
45	159
45	199
45	244
45	252
45	256
45	284
45	293
45	343
45	356
45	379
45	402
45	408
45	415
45	502
45	513
45	580
45	581
45	595
45	603
45	713
45	718
45	728
45	739
45	783
45	809
45	896
45	1016
45	1094
46	69
46	70
46	72
46	93
46	169
46	189
46	206
46	219
46	250
46	261
46	265
46	283
46	293
46	295
46	354
46	363
46	453
46	520
46	531
46	546
46	709
46	721
46	731
46	735
46	747
46	766
46	772
46	935
47	49
47	64
47	65
47	76
47	144
47	226
47	245
47	287
47	377
47	385
47	412
47	432
47	440
47	461
47	470
47	494
47	503
47	506
47	530
47	535
47	738
47	744
47	759
47	770
47	772
47	875
47	899
47	917
47	1013
48	30
48	72
48	131
48	136
48	139
48	157
48	201
48	217
48	221
48	228
48	236
48	271
48	275
48	299
48	316
48	319
48	373
48	393
48	412
48	506
48	517
48	539
48	540
48	566
48	593
48	704
48	706
48	707
48	726
48	746
48	750
48	752
48	769
48	783
48	869
48	893
48	911
48	926
48	980
48	1001
48	1007
48	1019
48	1106
49	21
49	93
49	97
49	100
49	144
49	183
49	191
49	203
49	220
49	232
49	279
49	359
49	382
49	440
49	516
49	525
49	544
49	566
49	582
49	595
49	703
49	715
49	727
49	755
49	763
49	765
49	781
49	793
49	827
49	839
49	1079
50	20
50	45
50	84
50	133
50	146
50	159
50	191
50	199
50	233
50	266
50	271
50	277
50	311
50	342
50	369
50	370
50	375
50	404
50	431
50	450
50	453
50	465
50	500
50	538
50	713
50	722
50	729
50	742
50	743
50	806
50	842
50	845
50	1061
51	84
51	99
51	123
51	160
51	168
51	186
51	244
51	317
51	321
51	361
51	391
51	438
51	454
51	465
51	473
51	508
51	540
51	551
51	572
51	708
51	712
51	743
51	788
51	902
51	923
51	935
52	2
52	65
52	78
52	157
52	170
52	175
52	183
52	187
52	207
52	230
52	233
52	256
52	258
52	269
52	346
52	373
52	380
52	397
52	405
52	419
52	425
52	440
52	446
52	454
52	460
52	481
52	485
52	496
52	505
52	526
52	543
52	571
52	584
52	591
52	602
52	603
52	733
52	748
52	760
52	763
52	766
52	791
52	815
52	893
52	941
52	950
52	1007
52	1064
53	43
53	121
53	133
53	151
53	207
53	278
53	320
53	327
53	343
53	429
53	432
53	451
53	494
53	504
53	511
53	526
53	535
53	552
53	702
53	735
53	746
53	778
53	791
53	833
53	896
53	956
53	971
53	1025
54	2
54	21
54	65
54	179
54	190
54	223
54	257
54	286
54	288
54	316
54	423
54	426
54	436
54	445
54	477
54	487
54	503
54	504
54	506
54	512
54	519
54	526
54	555
54	580
54	589
54	600
54	601
54	728
54	736
54	765
54	773
54	785
54	788
54	917
54	965
54	995
55	82
55	181
55	187
55	283
55	306
55	332
55	353
55	364
55	369
55	412
55	448
55	491
55	498
55	502
55	558
55	571
55	712
55	734
55	735
55	738
55	783
55	845
55	899
55	1001
56	43
56	48
56	86
56	116
56	136
56	145
56	149
56	166
56	178
56	247
56	321
56	422
56	450
56	473
56	488
56	518
56	549
56	555
56	565
56	700
56	714
56	732
56	743
56	783
56	795
56	821
56	1043
56	1079
57	1
57	21
57	45
57	95
57	99
57	104
57	184
57	209
57	284
57	303
57	309
57	342
57	397
57	419
57	432
57	454
57	488
57	500
57	519
57	537
57	546
57	583
57	589
57	606
57	716
57	730
57	736
57	929
57	992
57	1040
57	1079
57	1103
58	12
58	33
58	101
58	138
58	159
58	166
58	199
58	313
58	363
58	367
58	378
58	467
58	504
58	532
58	594
58	723
58	733
58	737
58	784
58	872
58	905
58	959
58	965
58	1025
59	89
59	90
59	96
59	129
59	178
59	182
59	209
59	210
59	223
59	266
59	277
59	280
59	414
59	415
59	417
59	472
59	496
59	499
59	500
59	556
59	557
59	604
59	702
59	721
59	731
59	756
59	757
59	845
59	908
59	920
59	983
59	1022
59	1055
59	1109
60	27
60	31
60	56
60	89
60	94
60	121
60	124
60	126
60	130
60	166
60	269
60	315
60	335
60	351
60	353
60	421
60	436
60	462
60	523
60	536
60	547
60	595
60	703
60	720
60	732
60	775
60	789
60	803
60	833
60	842
60	869
60	1076
61	21
61	25
61	72
61	87
61	102
61	105
61	141
61	187
61	210
61	243
61	254
61	313
61	346
61	354
61	387
61	401
61	417
61	420
61	467
61	502
61	516
61	595
61	598
61	702
61	709
61	723
61	737
61	741
61	743
61	747
61	749
61	779
61	803
61	878
61	914
61	944
61	1013
61	1043
61	1088
61	1103
62	4
62	61
62	102
62	128
62	146
62	161
62	173
62	238
62	288
62	311
62	358
62	375
62	384
62	453
62	465
62	466
62	499
62	504
62	522
62	579
62	587
62	715
62	739
62	775
62	793
62	857
62	1070
62	1109
63	93
63	100
63	134
63	237
63	250
63	265
63	285
63	306
63	330
63	354
63	428
63	501
63	591
63	602
63	806
63	815
63	833
63	953
63	962
63	995
64	49
64	58
64	94
64	116
64	154
64	301
64	306
64	308
64	338
64	352
64	393
64	416
64	444
64	464
64	479
64	505
64	508
64	566
64	572
64	595
64	708
64	742
64	776
64	815
64	845
64	980
64	1016
64	1058
65	2
65	58
65	83
65	92
65	137
65	149
65	150
65	204
65	286
65	287
65	309
65	313
65	328
65	369
65	455
65	460
65	514
65	541
65	588
65	589
65	715
65	716
65	726
65	762
65	842
65	1064
65	1094
65	1097
66	64
66	127
66	129
66	163
66	232
66	362
66	377
66	379
66	399
66	421
66	450
66	452
66	482
66	506
66	549
66	563
66	578
66	599
66	605
66	707
66	737
66	751
66	774
66	821
66	848
66	902
66	1016
66	1046
66	1061
66	1073
\.


--
-- Data for Name: team; Type: TABLE DATA; Schema: spy; Owner: -
--

COPY team (team_id, name, meeting_frequency) FROM stdin;
1	Renegade	weekly
2	Haberdash	weekly
3	Roadkill	monthly
4	Oink	monthly
5	Blaster	monthly
6	Timebomb	monthly
7	FlyOnTheWall	weekly
8	Terminator	monthly
9	BumbleBee	weekly
10	Blackout	monthly
11	Cyclone	monthly
12	SpecialForces	monthly
13	Gypsies	monthly
14	Beasties	monthly
15	Failsafe	monthly
16	Vikings	weekly
17	Rolaids	monthly
18	SqueakyClean	weekly
19	ShowBiz	monthly
20	Giraffe	monthly
21	Rimspeed	monthly
22	Leadphut	weekly
23	Charley Hunter	monthly
24	Blunt	Twice Monthly
25	Camaro	Semiannually
26	Thunderbird	monthly
27	Swing Voters	weekly
28	Cha Cha Cha	weekly
29	Ghost Hunters	weekly
30	Widow Makers	monthly
31	Boat Team 1	daily
32	Boat Team 2	daily
33	Boat Team 3	daily
34	Boat Team 4	daily
35	Boat Team 6	daily
36	Boat Team 7	daily
37	Jester	weekly
38	Scorpion	weekly
39	Blue Dagger	monthly
40	F Sharp	daily
42	Spoiler	monthly
44	Wired	daily
\.


--
-- Data for Name: teamrel; Type: TABLE DATA; Schema: spy; Owner: -
--

COPY teamrel (team_id, agent_id) FROM stdin;
1	168
1	488
1	560
1	581
1	604
1	702
1	730
1	733
1	753
1	1085
2	1
2	152
2	184
2	281
2	391
2	458
2	491
2	502
2	780
2	788
3	39
3	87
3	361
3	452
3	490
3	491
3	527
3	543
3	554
3	974
4	191
4	233
4	370
4	554
4	563
4	1004
4	1007
4	1103
5	198
5	252
5	324
5	412
5	461
5	561
5	769
5	815
6	5
6	261
6	281
6	326
6	389
6	437
6	492
6	769
6	947
7	94
7	108
7	265
7	315
7	409
7	440
7	454
7	469
7	475
7	481
8	174
8	186
8	320
8	476
8	587
8	719
8	785
8	818
8	1007
8	1073
9	4
9	131
9	188
9	206
9	217
9	488
9	505
9	735
9	956
10	101
10	258
10	336
10	353
10	498
10	511
10	706
10	789
10	812
10	920
11	59
11	70
11	81
11	87
11	101
11	320
11	367
11	788
11	899
11	911
12	55
12	83
12	84
12	199
12	252
12	453
12	528
12	1025
12	1097
13	85
13	145
13	183
13	274
13	398
13	401
13	709
13	836
13	947
13	950
14	48
14	95
14	96
14	172
14	179
14	295
14	427
14	571
14	715
14	953
15	338
15	352
15	353
15	408
15	458
15	741
15	754
15	755
15	860
15	1097
16	70
16	185
16	359
16	463
16	489
16	518
16	542
16	565
16	743
16	806
17	122
17	221
17	410
17	418
17	425
17	517
17	518
17	559
17	583
17	720
18	3
18	20
18	256
18	369
18	554
18	743
18	753
18	789
19	107
19	133
19	219
19	266
19	355
19	399
19	549
19	599
19	896
20	80
20	131
20	141
20	223
20	437
20	438
20	604
20	776
20	1043
21	43
21	148
21	243
21	332
21	359
21	361
21	467
21	550
21	833
22	375
22	473
22	492
22	521
22	540
22	589
22	714
22	1037
23	92
23	190
23	205
23	332
23	408
23	474
23	529
23	554
23	962
23	1091
24	124
24	278
24	448
24	452
24	460
24	496
24	521
24	564
24	721
24	845
25	139
25	170
25	192
25	286
25	306
25	718
25	959
25	1085
26	91
26	277
26	307
26	309
26	375
26	378
26	535
26	572
26	1034
27	69
27	181
27	326
27	356
27	444
27	447
27	605
27	787
27	920
27	1103
28	226
28	239
28	539
28	591
28	604
28	760
28	781
28	998
28	1010
28	1025
29	4
29	25
29	160
29	283
29	379
29	554
29	780
29	851
29	1016
30	186
30	301
30	386
30	429
30	579
30	601
30	604
30	755
30	774
31	76
31	108
31	112
31	126
31	149
31	454
31	536
31	755
31	842
31	899
32	183
32	198
32	247
32	258
32	727
32	740
32	756
32	815
32	908
32	956
33	20
33	113
33	297
33	549
33	550
33	561
33	604
33	747
33	782
34	219
34	228
34	303
34	321
34	404
34	451
34	593
34	766
34	914
35	420
35	541
35	566
35	571
35	717
35	836
35	941
35	1094
36	105
36	141
36	189
36	203
36	477
36	521
36	787
36	795
37	174
37	324
37	391
37	518
37	580
37	869
37	1064
37	1085
38	22
38	78
38	113
38	150
38	155
38	358
38	498
38	585
38	962
39	184
39	271
39	277
39	449
39	462
39	473
39	583
39	709
40	61
40	191
40	212
40	317
40	360
40	378
40	419
40	770
40	1076
40	1109
42	328
44	106
44	436
44	603
\.


SET search_path = store, pg_catalog;

--
-- Data for Name: pricelist; Type: TABLE DATA; Schema: store; Owner: -
--

COPY pricelist (store, beverage, size, price) FROM stdin;
Plaid Pantry	Whole Milk	16	$1.15
Plaid Pantry	2% Milk	16	$1.05
Plaid Pantry	Whole Milk	64	$3.20
Plaid Pantry	Pepsi	12	$0.70
Plaid Pantry	Pepsi	20	$0.95
7-11	Whole Milk	8	$0.65
7-11	Chocolate Milk	8	$0.65
7-11	Whole Milk	16	$1.10
7-11	2% Milk	16	$1.00
7-11	Coke	12	$0.65
7-11	Diet Coke	12	$0.65
7-11	Coke	20	$1.10
7-11	Diet Coke	20	$1.10
7-11	Diet Caffeine-Free Cherry Low-Fizz Vitamin-Fortified Coke	20	$1.10
Circle K	Whole Milk	8	$0.60
Circle K	Whole Milk	16	$1.20
Circle K	Whole Milk	32	$2.30
Circle K	Whole Milk	128	$4.10
Circle K	Coke	20	$1.15
Circle K	Diet Coke	20	$1.15
Circle K	Coke	32	$2.10
Circle K	Diet Coke	32	$2.05
Safeway	Skim Milk	16	$1.20
Safeway	Skim Milk	32	$2.00
Safeway	2% Milk	16	$1.25
Safeway	2% Milk	64	$2.75
Safeway	Diet Pepsi	12	$0.60
Safeway	Diet Coke	12	$0.60
Plaid Pantry	Diet Pepsi	12	$0.70
\.


SET search_path = sailors, pg_catalog;

--
-- Name: boats_pkey; Type: CONSTRAINT; Schema: sailors; Owner: -; Tablespace: 
--

ALTER TABLE ONLY boats
    ADD CONSTRAINT boats_pkey PRIMARY KEY (bid);


--
-- Name: reserves_pkey; Type: CONSTRAINT; Schema: sailors; Owner: -; Tablespace: 
--

ALTER TABLE ONLY reserves
    ADD CONSTRAINT reserves_pkey PRIMARY KEY (sid, bid);


--
-- Name: sailors_pkey; Type: CONSTRAINT; Schema: sailors; Owner: -; Tablespace: 
--

ALTER TABLE ONLY sailors
    ADD CONSTRAINT sailors_pkey PRIMARY KEY (sid);


SET search_path = spy, pg_catalog;

--
-- Name: affiliation_pkey; Type: CONSTRAINT; Schema: spy; Owner: -; Tablespace: 
--

ALTER TABLE ONLY affiliation
    ADD CONSTRAINT affiliation_pkey PRIMARY KEY (aff_id);


--
-- Name: affiliationrel_pkey; Type: CONSTRAINT; Schema: spy; Owner: -; Tablespace: 
--

ALTER TABLE ONLY affiliationrel
    ADD CONSTRAINT affiliationrel_pkey PRIMARY KEY (aff_id, agent_id);


--
-- Name: agent_pkey; Type: CONSTRAINT; Schema: spy; Owner: -; Tablespace: 
--

ALTER TABLE ONLY agent
    ADD CONSTRAINT agent_pkey PRIMARY KEY (agent_id);


--
-- Name: language_pkey; Type: CONSTRAINT; Schema: spy; Owner: -; Tablespace: 
--

ALTER TABLE ONLY language
    ADD CONSTRAINT language_pkey PRIMARY KEY (lang_id);


--
-- Name: languagerel_pkey; Type: CONSTRAINT; Schema: spy; Owner: -; Tablespace: 
--

ALTER TABLE ONLY languagerel
    ADD CONSTRAINT languagerel_pkey PRIMARY KEY (lang_id, agent_id);


--
-- Name: mission_pkey; Type: CONSTRAINT; Schema: spy; Owner: -; Tablespace: 
--

ALTER TABLE ONLY mission
    ADD CONSTRAINT mission_pkey PRIMARY KEY (mission_id);


--
-- Name: securityclearance_pkey; Type: CONSTRAINT; Schema: spy; Owner: -; Tablespace: 
--

ALTER TABLE ONLY securityclearance
    ADD CONSTRAINT securityclearance_pkey PRIMARY KEY (sc_id);


--
-- Name: skill_pkey; Type: CONSTRAINT; Schema: spy; Owner: -; Tablespace: 
--

ALTER TABLE ONLY skill
    ADD CONSTRAINT skill_pkey PRIMARY KEY (skill_id);


--
-- Name: skillrel_pkey; Type: CONSTRAINT; Schema: spy; Owner: -; Tablespace: 
--

ALTER TABLE ONLY skillrel
    ADD CONSTRAINT skillrel_pkey PRIMARY KEY (skill_id, agent_id);


--
-- Name: team_pkey; Type: CONSTRAINT; Schema: spy; Owner: -; Tablespace: 
--

ALTER TABLE ONLY team
    ADD CONSTRAINT team_pkey PRIMARY KEY (team_id);


--
-- Name: teamrel_pkey; Type: CONSTRAINT; Schema: spy; Owner: -; Tablespace: 
--

ALTER TABLE ONLY teamrel
    ADD CONSTRAINT teamrel_pkey PRIMARY KEY (team_id, agent_id);


SET search_path = sailors, pg_catalog;

--
-- Name: reserves_bid_fkey; Type: FK CONSTRAINT; Schema: sailors; Owner: -
--

ALTER TABLE ONLY reserves
    ADD CONSTRAINT reserves_bid_fkey FOREIGN KEY (bid) REFERENCES boats(bid);


--
-- Name: reserves_sid_fkey; Type: FK CONSTRAINT; Schema: sailors; Owner: -
--

ALTER TABLE ONLY reserves
    ADD CONSTRAINT reserves_sid_fkey FOREIGN KEY (sid) REFERENCES sailors(sid);


SET search_path = spy, pg_catalog;

--
-- Name: affiliationrel_aff_id_fkey; Type: FK CONSTRAINT; Schema: spy; Owner: -
--

ALTER TABLE ONLY affiliationrel
    ADD CONSTRAINT affiliationrel_aff_id_fkey FOREIGN KEY (aff_id) REFERENCES affiliation(aff_id);


--
-- Name: affiliationrel_agent_id_fkey; Type: FK CONSTRAINT; Schema: spy; Owner: -
--

ALTER TABLE ONLY affiliationrel
    ADD CONSTRAINT affiliationrel_agent_id_fkey FOREIGN KEY (agent_id) REFERENCES agent(agent_id);


--
-- Name: agent_clearance_id_fkey; Type: FK CONSTRAINT; Schema: spy; Owner: -
--

ALTER TABLE ONLY agent
    ADD CONSTRAINT agent_clearance_id_fkey FOREIGN KEY (clearance_id) REFERENCES securityclearance(sc_id);


--
-- Name: languagerel_agent_id_fkey; Type: FK CONSTRAINT; Schema: spy; Owner: -
--

ALTER TABLE ONLY languagerel
    ADD CONSTRAINT languagerel_agent_id_fkey FOREIGN KEY (agent_id) REFERENCES agent(agent_id);


--
-- Name: languagerel_lang_id_fkey; Type: FK CONSTRAINT; Schema: spy; Owner: -
--

ALTER TABLE ONLY languagerel
    ADD CONSTRAINT languagerel_lang_id_fkey FOREIGN KEY (lang_id) REFERENCES language(lang_id);


--
-- Name: mission_access_id_fkey; Type: FK CONSTRAINT; Schema: spy; Owner: -
--

ALTER TABLE ONLY mission
    ADD CONSTRAINT mission_access_id_fkey FOREIGN KEY (access_id) REFERENCES securityclearance(sc_id);


--
-- Name: mission_team_id_fkey; Type: FK CONSTRAINT; Schema: spy; Owner: -
--

ALTER TABLE ONLY mission
    ADD CONSTRAINT mission_team_id_fkey FOREIGN KEY (team_id) REFERENCES team(team_id);


--
-- Name: skillrel_agent_id_fkey; Type: FK CONSTRAINT; Schema: spy; Owner: -
--

ALTER TABLE ONLY skillrel
    ADD CONSTRAINT skillrel_agent_id_fkey FOREIGN KEY (agent_id) REFERENCES agent(agent_id);


--
-- Name: skillrel_skill_id_fkey; Type: FK CONSTRAINT; Schema: spy; Owner: -
--

ALTER TABLE ONLY skillrel
    ADD CONSTRAINT skillrel_skill_id_fkey FOREIGN KEY (skill_id) REFERENCES skill(skill_id);


--
-- Name: teamrel_agent_id_fkey; Type: FK CONSTRAINT; Schema: spy; Owner: -
--

ALTER TABLE ONLY teamrel
    ADD CONSTRAINT teamrel_agent_id_fkey FOREIGN KEY (agent_id) REFERENCES agent(agent_id);


--
-- Name: teamrel_team_id_fkey; Type: FK CONSTRAINT; Schema: spy; Owner: -
--

ALTER TABLE ONLY teamrel
    ADD CONSTRAINT teamrel_team_id_fkey FOREIGN KEY (team_id) REFERENCES team(team_id);


--
-- Name: sailors; Type: ACL; Schema: -; Owner: -
--

REVOKE ALL ON SCHEMA sailors FROM PUBLIC;


--
-- Name: spy; Type: ACL; Schema: -; Owner: -
--

REVOKE ALL ON SCHEMA spy FROM PUBLIC;


--
-- Name: store; Type: ACL; Schema: -; Owner: -
--

REVOKE ALL ON SCHEMA store FROM PUBLIC;


SET search_path = sailors, pg_catalog;

--
-- Name: boats; Type: ACL; Schema: sailors; Owner: -
--

REVOKE ALL ON TABLE boats FROM PUBLIC;


--
-- Name: reserves; Type: ACL; Schema: sailors; Owner: -
--

REVOKE ALL ON TABLE reserves FROM PUBLIC;


--
-- Name: sailors; Type: ACL; Schema: sailors; Owner: -
--

REVOKE ALL ON TABLE sailors FROM PUBLIC;


SET search_path = spy, pg_catalog;

--
-- Name: affiliation; Type: ACL; Schema: spy; Owner: -
--

REVOKE ALL ON TABLE affiliation FROM PUBLIC;


--
-- Name: affiliationrel; Type: ACL; Schema: spy; Owner: -
--

REVOKE ALL ON TABLE affiliationrel FROM PUBLIC;


--
-- Name: agent; Type: ACL; Schema: spy; Owner: -
--

REVOKE ALL ON TABLE agent FROM PUBLIC;


--
-- Name: language; Type: ACL; Schema: spy; Owner: -
--

REVOKE ALL ON TABLE language FROM PUBLIC;


--
-- Name: languagerel; Type: ACL; Schema: spy; Owner: -
--

REVOKE ALL ON TABLE languagerel FROM PUBLIC;


--
-- Name: mission; Type: ACL; Schema: spy; Owner: -
--

REVOKE ALL ON TABLE mission FROM PUBLIC;


--
-- Name: securityclearance; Type: ACL; Schema: spy; Owner: -
--

REVOKE ALL ON TABLE securityclearance FROM PUBLIC;


--
-- Name: skill; Type: ACL; Schema: spy; Owner: -
--

REVOKE ALL ON TABLE skill FROM PUBLIC;


--
-- Name: skillrel; Type: ACL; Schema: spy; Owner: -
--

REVOKE ALL ON TABLE skillrel FROM PUBLIC;


--
-- Name: team; Type: ACL; Schema: spy; Owner: -
--

REVOKE ALL ON TABLE team FROM PUBLIC;


--
-- Name: teamrel; Type: ACL; Schema: spy; Owner: -
--

REVOKE ALL ON TABLE teamrel FROM PUBLIC;


SET search_path = store, pg_catalog;

--
-- Name: pricelist; Type: ACL; Schema: store; Owner: -
--

REVOKE ALL ON TABLE pricelist FROM PUBLIC;


--
-- PostgreSQL database dump complete
--

