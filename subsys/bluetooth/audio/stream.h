/* @file
 * @brief Internal APIs for Audio Stream handling

 * Copyright (c) 2020 Intel Corporation
 * Copyright (c) 2021-2022 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/* Connect ISO channel */
int bt_audio_stream_connect(struct bt_audio_stream *stream);

/* Disconnect ISO channel */
int bt_audio_stream_disconnect(struct bt_audio_stream *stream);

void bt_audio_stream_reset(struct bt_audio_stream *stream);

void bt_audio_stream_attach(struct bt_conn *conn, struct bt_audio_stream *stream,
			    struct bt_audio_ep *ep,
			    struct bt_codec *codec);

void bt_audio_codec_to_iso_path(struct bt_iso_chan_path *path,
				const struct bt_codec *codec);
void bt_audio_codec_qos_to_iso_qos(struct bt_iso_chan_io_qos *io,
				   const struct bt_codec_qos *codec_qos);

void bt_audio_stream_detach(struct bt_audio_stream *stream);

bool bt_audio_valid_qos(const struct bt_codec_qos *qos);

bool bt_audio_valid_stream_qos(const struct bt_audio_stream *stream,
			     const struct bt_codec_qos *qos);

int bt_audio_stream_iso_listen(struct bt_audio_stream *stream);

struct bt_iso_chan *bt_audio_stream_iso_chan_get(struct bt_audio_stream *stream);
