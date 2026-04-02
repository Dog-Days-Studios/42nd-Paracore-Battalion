class XtdGearModels
{
    class CfgWeapons
    {
        class Para42_Helmets_Standard
        {
            label = "[42nd] Standard Helmets";
            author = "HoundaCivic";
            options[] = {"helmet"};

            class helmet
            {
                label = "Helmet";
                values[] =
                {
                    "h_ct_p2",
                    "h_cpltl_p2",
                    "h_csgt_p2",
                    "h_cst_p2",
                    "h_cvt_p2",
                    "h_nco_p2"
                };
                class h_ct_p2 { label = "P2"; };
                class h_cpltl_p2 { label = "Platoon Lead P2"; };
                class h_csgt_p2 { label = "Squad Lead P2"; };
                class h_cst_p2 { label = "Senior Trooper P2"; };
                class h_cvt_p2 { label = "CVT P2"; };
                class h_nco_p2 { label = "NCO P2"; };
            };
        };

        class Para42_Helmets_Medic
        {
            label = "[42nd] Medic Helmets";
            author = "HoundaCivic";
            options[] = {"helmet"};

            class helmet
            {
                label = "Helmet";
                values[] =
                {
                    "h_medic_p2",
                    "h_cvt_medic_p2",
                    "h_squad_medic_p2"
                };
                class h_medic_p2 { label = "Medic P2"; };
                class h_cvt_medic_p2 { label = "CVT Medic P2"; };
                class h_squad_medic_p2 { label = "Squad Medic P2"; };
            };
        };

        class Para42_Helmets_EOD
        {
            label = "[42nd] EOD Helmets";
            author = "HoundaCivic";
            options[] = {"helmet"};

            class helmet
            {
                label = "Helmet";
                values[] =
                {
                    "h_eod_p2",
                    "h_eod_vet",
                    "h_eod_squad",
                    "h_eod_senior"
                };
                class h_eod_p2 { label = "EOD P2"; };
                class h_eod_vet { label = "EOD Veteran"; };
                class h_eod_squad { label = "EOD Squad"; };
                class h_eod_senior { label = "EOD Senior"; };
            };
        };

        class Para42_Helmets_Marksman
        {
            label = "[42nd] Marksman Helmets";
            author = "HoundaCivic";
            options[] = {"helmet"};

            class helmet
            {
                label = "Helmet";
                values[] =
                {
                    "h_marksman",
                    "h_marksman_squad",
                    "h_marksman_senior",
                    "h_marksman_vet"
                };
                class h_marksman { label = "Marksman"; };
                class h_marksman_squad { label = "Marksman Squad"; };
                class h_marksman_senior { label = "Marksman Senior"; };
                class h_marksman_vet { label = "Marksman Veteran"; };
            };
        };

        class Para42_Helmets_RTO
        {
            label = "[42nd] RTO Helmets";
            author = "HoundaCivic";
            options[] = {"helmet"};

            class helmet
            {
                label = "Helmet";
                values[] =
                {
                    "h_rto_sr",
                    "h_rto_sr_vet",
                    "h_rto_lr",
                    "h_rto_lr_vet"
                };
                class h_rto_sr { label = "RTO SR"; };
                class h_rto_sr_vet { label = "RTO SR Veteran"; };
                class h_rto_lr { label = "RTO LR"; };
                class h_rto_lr_vet { label = "RTO LR Veteran"; };
            };
        };

        class Para42_Helmets_Pilot
        {
            label = "[42nd] Pilot Helmets";
            author = "HoundaCivic";
            options[] = {"helmet"};

            class helmet
            {
                label = "Helmet";
                values[] =
                {
                    "h_pilot_trainee",
                    "h_pilot_wo1",
                    "h_pilot_wo2",
                    "h_pilot_wo3"
                };
                class h_pilot_trainee { label = "Pilot Trainee"; };
                class h_pilot_wo1 { label = "Pilot WO1"; };
                class h_pilot_wo2 { label = "Pilot WO2"; };
                class h_pilot_wo3 { label = "Pilot WO3"; };
            };
        };

        class Para42_Helmets_ARF
        {
            label = "[42nd] ARF Helmets";
            author = "HoundaCivic";
            options[] = {"helmet"};

            class helmet
            {
                label = "Helmet";
                values[] = {"h_arf"};
                class h_arf { label = "ARF"; };
            };
        };

        class Para42_Helmets_Customs
        {
            label = "[42nd] Custom Helmets";
            author = "HoundaCivic";
            options[] = {"helmet"};

            class helmet
            {
                label = "Helmet";
                values[] =
                {
                    "h_rose",
                    "h_hound",
                    "h_walker"
                };
                class h_rose { label = "Rose"; };
                class h_hound { label = "Hound"; };
                class h_walker { label = "Walker"; };
            };
        };

        class Para42_Uniforms_Standard
        {
            label = "[42nd] Standard Uniforms";
            author = "HoundaCivic";
            options[] = {"uniform"};

            class uniform
            {
                label = "Uniform";
                values[] =
                {
                    "u_basic",
                    "u_cpltl",
                    "u_csgt",
                    "u_cst",
                    "u_cvt",
                    "u_nco"
                };
                class u_basic { label = "Basic"; };
                class u_cpltl { label = "Platoon Lead"; };
                class u_csgt { label = "Squad Lead"; };
                class u_cst { label = "CST"; };
                class u_cvt { label = "CVT"; };
                class u_nco { label = "NCO"; };
            };
        };

        class Para42_Uniforms_Medic
        {
            label = "[42nd] Medic Uniforms";
            author = "HoundaCivic";
            options[] = {"uniform"};

            class uniform
            {
                label = "Uniform";
                values[] =
                {
                    "u_medic",
                    "u_cvt_medic",
                    "u_squad_medic"
                };
                class u_medic { label = "Medic"; };
                class u_cvt_medic { label = "CVT Medic"; };
                class u_squad_medic { label = "Squad Medic"; };
            };
        };

        class Para42_Uniforms_EOD
        {
            label = "[42nd] EOD Uniforms";
            author = "HoundaCivic";
            options[] = {"uniform"};

            class uniform
            {
                label = "Uniform";
                values[] =
                {
                    "u_eod",
                    "u_eod_vet",
                    "u_eod_squad",
                    "u_eod_senior"
                };
                class u_eod { label = "EOD"; };
                class u_eod_vet { label = "EOD Veteran"; };
                class u_eod_squad { label = "EOD Squad"; };
                class u_eod_senior { label = "EOD Senior"; };
            };
        };

        class Para42_Uniforms_Marksman
        {
            label = "[42nd] Marksman Uniforms";
            author = "HoundaCivic";
            options[] = {"uniform"};

            class uniform
            {
                label = "Uniform";
                values[] =
                {
                    "u_marksman",
                    "u_marksman_squad",
                    "u_marksman_senior",
                    "u_marksman_vet"
                };
                class u_marksman { label = "Marksman"; };
                class u_marksman_squad { label = "Marksman Squad"; };
                class u_marksman_senior { label = "Marksman Senior"; };
                class u_marksman_vet { label = "Marksman Veteran"; };
            };
        };

        class Para42_Uniforms_Customs
        {
            label = "[42nd] Custom Uniforms";
            author = "HoundaCivic";
            options[] = {"uniform"};

            class uniform
            {
                label = "Uniform";
                values[] =
                {
                    "u_rose",
                    "u_hound",
                    "u_walker"
                };
                class u_rose { label = "Rose"; };
                class u_hound { label = "Hound"; };
                class u_walker { label = "Walker"; };
            };
        };

        class Para42_NVGs
        {
            label = "[42nd] NVGs";
            author = "HoundaCivic";
            options[] = {"nvg"};

            class nvg
            {
                label = "NVG";
                alwaysSelectable = 1;
                values[] =
                {
                    "n_macrobinoculars_off",
                    "n_macrobinoculars_on",
                    "n_rangefinder",
                    "n_crewman"
                };
                class n_macrobinoculars_off { label = "Macrobinoculars"; };
                class n_macrobinoculars_on { label = "Macrobinoculars (On)"; };
                class n_rangefinder { label = "Rangefinder"; };
                class n_crewman { label = "Crewman NVG"; };
            };
        };

        class Para42_Rifles
        {
            label = "[42nd] Rifles";
            author = "HoundaCivic";
            options[] = {"weapon"};

            class weapon
            {
                label = "Rifle";
                values[] =
                {
                    "w_dc15a_3as",
                    "w_dc15a_ida",
                    "w_dc15a_jlts",
                    "w_dc15a_ls",
                    "w_dc15a_jlts_plastic",
                    "w_dc15a_ls_wooden",
                    "w_dc15ac_ls",
                    "w_dc15br_ls",
                    "w_dc15br_ls_wooden",
                    "w_dc15c_3as",
                    "w_dc15s_3as",
                    "w_dc15s_ida",
                    "w_dc15s_jlts",
                    "w_dc15s_ls",
                    "w_fa11_ida"
                };
                class w_dc15a_3as { label = "DC15A (3AS)"; };
                class w_dc15a_ida { label = "DC15A (IDA)"; };
                class w_dc15a_jlts { label = "DC15A (JLTS)"; };
                class w_dc15a_ls { label = "DC15A (LS)"; };
                class w_dc15a_jlts_plastic { label = "DC15A Plastic (JLTS)"; };
                class w_dc15a_ls_wooden { label = "DC15A Wooden (LS)"; };
                class w_dc15ac_ls { label = "DC15AC (LS)"; };
                class w_dc15br_ls { label = "DC15BR (LS)"; };
                class w_dc15br_ls_wooden { label = "DC15BR Wooden (LS)"; };
                class w_dc15c_3as { label = "DC15C (3AS)"; };
                class w_dc15s_3as { label = "DC15S (3AS)"; };
                class w_dc15s_ida { label = "DC15S (IDA)"; };
                class w_dc15s_jlts { label = "DC15S (JLTS)"; };
                class w_dc15s_ls { label = "DC15S (LS)"; };
                class w_fa11_ida { label = "FA11 (IDA)"; };
            };
        };

        class Para42_LMGs
        {
            label = "[42nd] LMGs";
            author = "HoundaCivic";
            options[] = {"weapon"};

            class weapon
            {
                label = "LMG";
                values[] =
                {
                    "w_dlt15_ida",
                    "w_dlt19_3as",
                    "w_dlt19_ida",
                    "w_dlt19d_ida",
                    "w_z6_ida",
                    "w_z6_jlts",
                    "w_z6_ls"
                };
                class w_dlt15_ida { label = "DLT15 (IDA)"; };
                class w_dlt19_3as { label = "DLT19 (3AS)"; };
                class w_dlt19_ida { label = "DLT19 (IDA)"; };
                class w_dlt19d_ida { label = "DLT19D (IDA)"; };
                class w_z6_ida { label = "Z6 (IDA)"; };
                class w_z6_jlts { label = "Z6 (JLTS)"; };
                class w_z6_ls { label = "Z6 (LS)"; };
            };
        };

        class Para42_Snipers
        {
            label = "[42nd] Snipers";
            author = "HoundaCivic";
            options[] = {"weapon"};

            class weapon
            {
                label = "Sniper";
                values[] =
                {
                    "w_773firepuncher_ida",
                    "w_774cx_ida",
                    "w_dc15x_ida",
                    "w_dc15x_jlts",
                    "w_dc15x_ls",
                    "w_dw32s_jlts",
                    "w_firepuncher_ls",
                    "w_galaar90_ida",
                    "w_iqa11_ida",
                    "w_valken38x_3as"
                };
                class w_773firepuncher_ida { label = "773FIREPUNCHER (IDA)"; };
                class w_774cx_ida { label = "774CX (IDA)"; };
                class w_dc15x_ida { label = "DC15X (IDA)"; };
                class w_dc15x_jlts { label = "DC15X (JLTS)"; };
                class w_dc15x_ls { label = "DC15X (LS)"; };
                class w_dw32s_jlts { label = "DW32S (JLTS)"; };
                class w_firepuncher_ls { label = "FIREPUNCHER (LS)"; };
                class w_galaar90_ida { label = "GALAAR90 (IDA)"; };
                class w_iqa11_ida { label = "IQA11 (IDA)"; };
                class w_valken38x_3as { label = "VALKEN38X (3AS)"; };
            };
        };

        class Para42_Launchers
        {
            label = "[42nd] Launchers";
            author = "HoundaCivic";
            options[] = {"weapon"};

            class weapon
            {
                label = "Launcher";
                values[] =
                {
                    "w_rps6_ida"
                };
                class w_rps6_ida { label = "RPS6 (IDA)"; };
            };
        };

        class Para42_GrenadeLaunchers
        {
            label = "[42nd] Grenade Launchers";
            author = "HoundaCivic";
            options[] = {"weapon"};

            class weapon
            {
                label = "Grenade Launcher";
                values[] =
                {
                    "w_dc15a_gl_3as",
                    "w_dc15a_gl_jlts",
                    "w_dc15a_gl_jlts_plastic",
                    "w_dc15c_gl_3as",
                    "w_dc15le_ida",
                    "w_dc15s_gl_3as",
                    "w_dc15s_gl_ida",
                    "w_dp23_gl_3as"
                };
                class w_dc15a_gl_3as { label = "DC15A GL (3AS)"; };
                class w_dc15a_gl_jlts { label = "DC15A GL (JLTS)"; };
                class w_dc15a_gl_jlts_plastic { label = "DC15A GL Plastic (JLTS)"; };
                class w_dc15c_gl_3as { label = "DC15C GL (3AS)"; };
                class w_dc15le_ida { label = "DC15LE (IDA)"; };
                class w_dc15s_gl_3as { label = "DC15S GL (3AS)"; };
                class w_dc15s_gl_ida { label = "DC15S GL (IDA)"; };
                class w_dp23_gl_3as { label = "DP23 GL (3AS)"; };
            };
        };

        class Para42_Pistols
        {
            label = "[42nd] Pistols";
            author = "HoundaCivic";
            options[] = {"weapon"};

            class weapon
            {
                label = "Pistol";
                alwaysSelectable = 1;
                values[] =
                {
                    "p_dc15p_ida",
                    "p_dc17_ida",
                    "p_dc15sa_ls",
                    "p_dc17s_ls",
                    "p_dc17s_dual_ls",
                    "p_dc17s_3as",
                    "p_dc17s_dual_3as",
                    "p_fusioncutter_3as"
                };
                class p_dc15p_ida { label = "DC15P (IDA)"; };
                class p_dc17_ida { label = "DC17 (IDA)"; };
                class p_dc15sa_ls { label = "DC15SA (LS)"; };
                class p_dc17s_ls { label = "DC17S (LS)"; };
                class p_dc17s_dual_ls { label = "DC17S Dual (LS)"; };
                class p_dc17s_3as { label = "DC17S (3AS)"; };
                class p_dc17s_dual_3as { label = "DC17S Dual (3AS)"; };
                class p_fusioncutter_3as { label = "Fusion Cutter (3AS)"; };
            };
        };
    };

    class CfgVehicles
    {
        class Para42_Backpacks
        {
            label = "[42nd] Backpacks";
            author = "HoundaCivic";
            options[] = {"pack"};

            class pack
            {
                label = "Pack";
                alwaysSelectable = 1;
                values[] =
                {
                    "b_portable_shield",
                    "b_jt12",
                    "b_grenade_rig",
                    "b_standard",
                    "b_ida_rucksack",
                    "b_rocket",
                    "b_radio",
                    "b_medic",
                    "b_heavy",
                    "b_ammo",
                    "b_minilr",
                    "b_rucksack",
                    "b_chest_rig",
                    "b_chest_rig_pouch",
                    "b_belt_bag",
                    "b_belt_bag_belt",
                    "b_belt_bag_leg",
                    "b_lr_attachment",
                    "b_belt_bag_attachment"
                };
                class b_portable_shield { label = "Portable Shield"; };
                class b_jt12 { label = "JT-12 Jetpack"; };
                class b_grenade_rig { label = "Grenade Rig"; };
                class b_standard { label = "Standard Backpack"; };
                class b_ida_rucksack { label = "IDA Rucksack"; };
                class b_rocket { label = "Rocket Backpack"; };
                class b_radio { label = "Radio Backpack"; };
                class b_medic { label = "Medic Backpack"; };
                class b_heavy { label = "Heavy Backpack"; };
                class b_ammo { label = "Ammo Backpack"; };
                class b_minilr { label = "Mini LR Backpack"; };
                class b_rucksack { label = "Rucksack"; };
                class b_chest_rig { label = "Chest Rig"; };
                class b_chest_rig_pouch { label = "Chest Rig Pouch"; };
                class b_belt_bag { label = "Belt Bag"; };
                class b_belt_bag_belt { label = "Belt Bag (Belt)"; };
                class b_belt_bag_leg { label = "Belt Bag (Leg)"; };
                class b_lr_attachment { label = "LR Attachment"; };
                class b_belt_bag_attachment { label = "Belt Bag Attachment"; };
            };
        };
    };
};

class XtdGearInfos
{
    class CfgWeapons
    {
        class 42nd_CT_P2_Helmet
        {
            model = "Para42_Helmets_Standard";
            helmet = "h_ct_p2";
        };
        class 42nd_CPLTL_P2_Helmet
        {
            model = "Para42_Helmets_Standard";
            helmet = "h_cpltl_p2";
        };
        class 42nd_CSGT_P2_Helmet
        {
            model = "Para42_Helmets_Standard";
            helmet = "h_csgt_p2";
        };
        class 42nd_CST_P2_Helmet
        {
            model = "Para42_Helmets_Standard";
            helmet = "h_cst_p2";
        };
        class 42nd_Medic_P2_Helmet
        {
            model = "Para42_Helmets_Medic";
            helmet = "h_medic_p2";
        };
        class 42nd_CVT_Medic_P2_Helmet
        {
            model = "Para42_Helmets_Medic";
            helmet = "h_cvt_medic_p2";
        };
        class 42nd_Squad_Medic_P2_Helmet
        {
            model = "Para42_Helmets_Medic";
            helmet = "h_squad_medic_p2";
        };
        class 42nd_CVT_P2_Helmet
        {
            model = "Para42_Helmets_Standard";
            helmet = "h_cvt_p2";
        };
        class 42nd_NCO_P2_Helmet
        {
            model = "Para42_Helmets_Standard";
            helmet = "h_nco_p2";
        };
        class 42nd_EOD_P2_Helmet
        {
            model = "Para42_Helmets_EOD";
            helmet = "h_eod_p2";
        };
        class 42nd_EOD_Vet_Helmet
        {
            model = "Para42_Helmets_EOD";
            helmet = "h_eod_vet";
        };
        class 42nd_EOD_Squad_Helmet
        {
            model = "Para42_Helmets_EOD";
            helmet = "h_eod_squad";
        };
        class 42nd_EOD_Senior_Helmet
        {
            model = "Para42_Helmets_EOD";
            helmet = "h_eod_senior";
        };
        class 42nd_Marksman_P2_Helmet
        {
            model = "Para42_Helmets_Marksman";
            helmet = "h_marksman";
        };
        class 42nd_Marksman_Squad_Helmet
        {
            model = "Para42_Helmets_Marksman";
            helmet = "h_marksman_squad";
        };
        class 42nd_Marksman_Senior_Helmet
        {
            model = "Para42_Helmets_Marksman";
            helmet = "h_marksman_senior";
        };
        class 42nd_Marksman_Vet_Helmet
        {
            model = "Para42_Helmets_Marksman";
            helmet = "h_marksman_vet";
        };
        class 42nd_SpecOps_SR_Helmet
        {
            model = "Para42_Helmets_RTO";
            helmet = "h_rto_sr";
        };
        class 42nd_SpecOps_SR_Vet_Helmet
        {
            model = "Para42_Helmets_RTO";
            helmet = "h_rto_sr_vet";
        };
        class 42nd_SpecOps_LR_Helmet
        {
            model = "Para42_Helmets_RTO";
            helmet = "h_rto_lr";
        };
        class 42nd_SpecOps_LR_Vet_Helmet
        {
            model = "Para42_Helmets_RTO";
            helmet = "h_rto_lr_vet";
        };
        class 42nd_ARF_Helmet
        {
            model = "Para42_Helmets_ARF";
            helmet = "h_arf";
        };
        class 42nd_Trainee_Pilot_Helmet
        {
            model = "Para42_Helmets_Pilot";
            helmet = "h_pilot_trainee";
        };
        class 42nd_WO1_Pilot_Helmet
        {
            model = "Para42_Helmets_Pilot";
            helmet = "h_pilot_wo1";
        };
        class 42nd_WO2_Pilot_Helmet
        {
            model = "Para42_Helmets_Pilot";
            helmet = "h_pilot_wo2";
        };
        class 42nd_WO3_Pilot_Helmet
        {
            model = "Para42_Helmets_Pilot";
            helmet = "h_pilot_wo3";
        };
        class 42nd_Rose_P2_Helmet
        {
            model = "Para42_Helmets_Customs";
            helmet = "h_rose";
        };
        class 42nd_Hound_P2_Helmet
        {
            model = "Para42_Helmets_Customs";
            helmet = "h_hound";
        };
        class 42nd_Walker_P2_Helmet
        {
            model = "Para42_Helmets_Customs";
            helmet = "h_walker";
        };

        class 42nd_Trooper_Uniform
        {
            model = "Para42_Uniforms_Standard";
            uniform = "u_basic";
        };
        class 42nd_CPLTL_Trooper_Uniform
        {
            model = "Para42_Uniforms_Standard";
            uniform = "u_cpltl";
        };
        class 42nd_CSGT_Trooper_Uniform
        {
            model = "Para42_Uniforms_Standard";
            uniform = "u_csgt";
        };
        class 42nd_CST_Trooper_Uniform
        {
            model = "Para42_Uniforms_Standard";
            uniform = "u_cst";
        };
        class 42nd_medic_Trooper_Uniform
        {
            model = "Para42_Uniforms_Medic";
            uniform = "u_medic";
        };
        class 42nd_CVT_Medic_Trooper_Uniform
        {
            model = "Para42_Uniforms_Medic";
            uniform = "u_cvt_medic";
        };
        class 42nd_Squad_Medic_Trooper_Uniform
        {
            model = "Para42_Uniforms_Medic";
            uniform = "u_squad_medic";
        };
        class 42nd_CVT_Trooper_Uniform
        {
            model = "Para42_Uniforms_Standard";
            uniform = "u_cvt";
        };
        class 42nd_NCO_Trooper_Uniform
        {
            model = "Para42_Uniforms_Standard";
            uniform = "u_nco";
        };
        class 42nd_EOD_Trooper_Uniform
        {
            model = "Para42_Uniforms_EOD";
            uniform = "u_eod";
        };
        class 42nd_EOD_Vet_Trooper_Uniform
        {
            model = "Para42_Uniforms_EOD";
            uniform = "u_eod_vet";
        };
        class 42nd_EOD_Squad_Trooper_Uniform
        {
            model = "Para42_Uniforms_EOD";
            uniform = "u_eod_squad";
        };
        class 42nd_EOD_Senior_Trooper_Uniform
        {
            model = "Para42_Uniforms_EOD";
            uniform = "u_eod_senior";
        };
        class 42nd_Marksman_Trooper_Uniform
        {
            model = "Para42_Uniforms_Marksman";
            uniform = "u_marksman";
        };
        class 42nd_Marksman_Squad_Trooper_Uniform
        {
            model = "Para42_Uniforms_Marksman";
            uniform = "u_marksman_squad";
        };
        class 42nd_Marksman_Senior_Trooper_Uniform
        {
            model = "Para42_Uniforms_Marksman";
            uniform = "u_marksman_senior";
        };
        class 42nd_Marksman_Vet_Trooper_Uniform
        {
            model = "Para42_Uniforms_Marksman";
            uniform = "u_marksman_vet";
        };
        class 42nd_Rose_Trooper_Uniform
        {
            model = "Para42_Uniforms_Customs";
            uniform = "u_rose";
        };
        class 42nd_Hound_Trooper_Uniform
        {
            model = "Para42_Uniforms_Customs";
            uniform = "u_hound";
        };
        class 42nd_Walker_Trooper_Uniform
        {
            model = "Para42_Uniforms_Customs";
            uniform = "u_walker";
        };
        class 42nd_NVG
        {
            model = "Para42_NVGs";
            nvg = "n_macrobinoculars_off";
        };
        class 42nd_NVG_flipped
        {
            model = "Para42_NVGs";
            nvg = "n_macrobinoculars_on";
        };
        class 42nd_Rangefinder
        {
            model = "Para42_NVGs";
            nvg = "n_rangefinder";
        };
        class 42nd_Tanker_Gunner
        {
            model = "Para42_NVGs";
            nvg = "n_crewman";
        };

        class 42nd_3AS_DC15A_F
        {
            model = "Para42_Rifles";
            weapon = "w_dc15a_3as";
        };
        class 42nd_3AS_DC15A_GL
        {
            model = "Para42_GrenadeLaunchers";
            weapon = "w_dc15a_gl_3as";
        };
        class 42nd_3AS_DC15C_F
        {
            model = "Para42_Rifles";
            weapon = "w_dc15c_3as";
        };
        class 42nd_3AS_DC15C_GL
        {
            model = "Para42_GrenadeLaunchers";
            weapon = "w_dc15c_gl_3as";
        };
        class 42nd_3AS_DC15S_F
        {
            model = "Para42_Rifles";
            weapon = "w_dc15s_3as";
        };
        class 42nd_3AS_DC15S_GL
        {
            model = "Para42_GrenadeLaunchers";
            weapon = "w_dc15s_gl_3as";
        };
        class 42nd_3AS_DC17S_Dual_F
        {
            model = "Para42_Pistols";
            weapon = "p_dc17s_dual_3as";
        };
        class 42nd_3AS_DC17S_F
        {
            model = "Para42_Pistols";
            weapon = "p_dc17s_3as";
        };
        class 42nd_3AS_DLT19
        {
            model = "Para42_LMGs";
            weapon = "w_dlt19_3as";
        };
        class 42nd_3AS_DP23_GL
        {
            model = "Para42_GrenadeLaunchers";
            weapon = "w_dp23_gl_3as";
        };
        class 42nd_3AS_FusionCutter_F
        {
            model = "Para42_Pistols";
            weapon = "p_fusioncutter_3as";
        };
        class 42nd_773Firepuncher
        {
            model = "Para42_Snipers";
            weapon = "w_773firepuncher_ida";
        };
        class 42nd_774CX
        {
            model = "Para42_Snipers";
            weapon = "w_774cx_ida";
        };
        class 42nd_DC15A
        {
            model = "Para42_Rifles";
            weapon = "w_dc15a_ida";
        };
        class 42nd_DC15LE
        {
            model = "Para42_GrenadeLaunchers";
            weapon = "w_dc15le_ida";
        };
        class 42nd_DC15P
        {
            model = "Para42_Pistols";
            weapon = "p_dc15p_ida";
        };
        class 42nd_DC15S
        {
            model = "Para42_Rifles";
            weapon = "w_dc15s_ida";
        };
        class 42nd_DC15S_UGL
        {
            model = "Para42_GrenadeLaunchers";
            weapon = "w_dc15s_gl_ida";
        };
        class 42nd_DC15X
        {
            model = "Para42_Snipers";
            weapon = "w_dc15x_ida";
        };
        class 42nd_DC17
        {
            model = "Para42_Pistols";
            weapon = "p_dc17_ida";
        };
        class 42nd_DLT15
        {
            model = "Para42_LMGs";
            weapon = "w_dlt15_ida";
        };
        class 42nd_DLT19
        {
            model = "Para42_LMGs";
            weapon = "w_dlt19_ida";
        };
        class 42nd_DLT19D
        {
            model = "Para42_LMGs";
            weapon = "w_dlt19d_ida";
        };
        class 42nd_FA11
        {
            model = "Para42_Rifles";
            weapon = "w_fa11_ida";
        };
        class 42nd_Galaar90
        {
            model = "Para42_Snipers";
            weapon = "w_galaar90_ida";
        };
        class 42nd_IQA11
        {
            model = "Para42_Snipers";
            weapon = "w_iqa11_ida";
        };
        class 42nd_JLTS_DC15A
        {
            model = "Para42_Rifles";
            weapon = "w_dc15a_jlts";
        };
        class 42nd_JLTS_DC15A_plastic
        {
            model = "Para42_Rifles";
            weapon = "w_dc15a_jlts_plastic";
        };
        class 42nd_JLTS_DC15A_ugl
        {
            model = "Para42_GrenadeLaunchers";
            weapon = "w_dc15a_gl_jlts";
        };
        class 42nd_JLTS_DC15A_ugl_plastic
        {
            model = "Para42_GrenadeLaunchers";
            weapon = "w_dc15a_gl_jlts_plastic";
        };
        class 42nd_JLTS_DC15S
        {
            model = "Para42_Rifles";
            weapon = "w_dc15s_jlts";
        };
        class 42nd_JLTS_DC15X
        {
            model = "Para42_Snipers";
            weapon = "w_dc15x_jlts";
        };
        class 42nd_JLTS_DW32S
        {
            model = "Para42_Snipers";
            weapon = "w_dw32s_jlts";
        };
        class 42nd_JLTS_Z6
        {
            model = "Para42_LMGs";
            weapon = "w_z6_jlts";
        };
        class 42nd_ls_weapon_dc15a
        {
            model = "Para42_Rifles";
            weapon = "w_dc15a_ls";
        };
        class 42nd_ls_weapon_dc15a_wooden
        {
            model = "Para42_Rifles";
            weapon = "w_dc15a_ls_wooden";
        };
        class 42nd_ls_weapon_dc15ac
        {
            model = "Para42_Rifles";
            weapon = "w_dc15ac_ls";
        };
        class 42nd_ls_weapon_dc15br
        {
            model = "Para42_Rifles";
            weapon = "w_dc15br_ls";
        };
        class 42nd_ls_weapon_dc15br_wooden
        {
            model = "Para42_Rifles";
            weapon = "w_dc15br_ls_wooden";
        };
        class 42nd_ls_weapon_dc15s
        {
            model = "Para42_Rifles";
            weapon = "w_dc15s_ls";
        };
        class 42nd_ls_weapon_dc15sa
        {
            model = "Para42_Pistols";
            weapon = "p_dc15sa_ls";
        };
        class 42nd_ls_weapon_dc15x
        {
            model = "Para42_Snipers";
            weapon = "w_dc15x_ls";
        };
        class 42nd_ls_weapon_dc17s
        {
            model = "Para42_Pistols";
            weapon = "p_dc17s_ls";
        };
        class 42nd_ls_weapon_dc17s_dual
        {
            model = "Para42_Pistols";
            weapon = "p_dc17s_dual_ls";
        };
        class 42nd_ls_weapon_firepuncher
        {
            model = "Para42_Snipers";
            weapon = "w_firepuncher_ls";
        };
        class 42nd_ls_weapon_z6
        {
            model = "Para42_LMGs";
            weapon = "w_z6_ls";
        };
        class 42nd_RPS6
        {
            model = "Para42_Launchers";
            weapon = "w_rps6_ida";
        };
        class 42nd_Valken38X
        {
            model = "Para42_Snipers";
            weapon = "w_valken38x_3as";
        };
        class 42nd_Z6
        {
            model = "Para42_LMGs";
            weapon = "w_z6_ida";
        };
    };

    class CfgVehicles
    {
        class 42nd_Portable_Shield_Backpack
        {
            model = "Para42_Backpacks";
            pack = "b_portable_shield";
        };
        class 42nd_JT12
        {
            model = "Para42_Backpacks";
            pack = "b_jt12";
        };
        class 42nd_Grenade_rig
        {
            model = "Para42_Backpacks";
            pack = "b_grenade_rig";
        };
        class 42nd_Standard_Backpack
        {
            model = "Para42_Backpacks";
            pack = "b_standard";
        };
        class 42nd_IDA_Backpack
        {
            model = "Para42_Backpacks";
            pack = "b_ida_rucksack";
        };
        class 42nd_Rocket_Backpack
        {
            model = "Para42_Backpacks";
            pack = "b_rocket";
        };
        class 42nd_Radio_Backpack
        {
            model = "Para42_Backpacks";
            pack = "b_radio";
        };
        class 42nd_Medic_Backpack
        {
            model = "Para42_Backpacks";
            pack = "b_medic";
        };
        class 42nd_Heavy_Backpack
        {
            model = "Para42_Backpacks";
            pack = "b_heavy";
        };
        class 42nd_Ammo_Backpack
        {
            model = "Para42_Backpacks";
            pack = "b_ammo";
        };
        class 42nd_MiniLR_Backpack
        {
            model = "Para42_Backpacks";
            pack = "b_minilr";
        };
        class 42nd_Rucksack
        {
            model = "Para42_Backpacks";
            pack = "b_rucksack";
        };
        class 42nd_ChestRig
        {
            model = "Para42_Backpacks";
            pack = "b_chest_rig";
        };
        class 42nd_ChestRig_Pouch
        {
            model = "Para42_Backpacks";
            pack = "b_chest_rig_pouch";
        };
        class 42nd_BeltBag
        {
            model = "Para42_Backpacks";
            pack = "b_belt_bag";
        };
        class 42nd_BeltBag_Belt
        {
            model = "Para42_Backpacks";
            pack = "b_belt_bag_belt";
        };
        class 42nd_BeltBag_Leg
        {
            model = "Para42_Backpacks";
            pack = "b_belt_bag_leg";
        };
        class 42nd_LR_Attachment
        {
            model = "Para42_Backpacks";
            pack = "b_lr_attachment";
        };
        class 42nd_BeltBag_Attachment
        {
            model = "Para42_Backpacks";
            pack = "b_belt_bag_attachment";
        };
    };
};

